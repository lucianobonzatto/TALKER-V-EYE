#include "SocketClient.h"

SocketClient::SocketClient() {
    init();
}

SocketClient::~SocketClient() {

}

void SocketClient::init() {
    //Create socket
    sockClient = socket(AF_INET, SOCK_STREAM, 0);
    if(sockClient == -1){
        cerr << "Can't create a socket!";
        return;
    }

    //Configure socket
    port = 9090; //port created in Java side
//    ipAdrress = "10.0.0.101"; //modificar de acordo com a rede
    ipAdrress = "192.168.0.27"; //modificar de acordo com a rede
//    ipAdrress = "127.0.0.1"; //modificar de acordo com a rede
//    ipAdrress = "192.168.43.130"; //modificar de acordo com a rede

    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT_CLIENT);
    inet_pton(AF_INET, ipAdrress.c_str(), &hint.sin_addr);

}

static void* sendMessageForJava(void *attr) {
    cout <<"send message init" << endl;

    SocketClient* socketClient = static_cast<SocketClient*>(attr);
//    sockaddr_in hint = socketClient->getHint();
    //======================== NEW PART FOR SOCK==================================//
    /*Como o socket é fechado no final dessa função, capaz de estar perdendo referencia aos atributos usados
    para fazer a conexão com o server, então toda vez que a função é chamada, ela cria novamente esse atributos */
    
   
    //Create socket
    int sockClient = socket(AF_INET, SOCK_STREAM, 0);
    if(sockClient == -1){
        cerr << "Can't create a socket!";
        pthread_exit(NULL);
    }

    //Configure socket
    int port = 9090; //port created in Java side
    string ipAdrress = "127.0.0.1"; //modificar de acordo com a rede
    sockaddr_in hint;

    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT_CLIENT);
    inet_pton(AF_INET, ipAdrress.c_str(), &hint.sin_addr);
    //==================================== END PART ============================================//

    //Connect socket with server
    int connectRes = connect(sockClient, (sockaddr*)&hint, sizeof(hint));
    if(connectRes == -1) {
       cerr << "Can't connect in server!" <<endl;
       pthread_exit(NULL);
    }

    cout << "connected in server!" << endl;
    int type = socketClient->getIdentifyType();
    int heightPxl = socketClient->getHeightPixel();
    int widthPxl = socketClient->getWidthPixel();
    int heightImage = socketClient->getHeightImage();
    int widthImage = socketClient->getWidthImage();

    string str = to_string(type);
    str.append(",");
    str.append(to_string(heightPxl));
    str.append(",");
    str.append(to_string(widthPxl));
    str.append(",");
    str.append(to_string(heightImage));
    str.append(",");
    str.append(to_string(widthImage));

    int sendRes = send(sockClient,  str.c_str(), str.size() +1, 0);
    if(sendRes == -1) {
       cout << "Could not send to server! \n";
    }

    close(sockClient);
    printf("close socket\n");
    pthread_exit(NULL);
}

static void* sendMessage(void *attr) {
    cout <<"send message init" << endl;
    
    SocketClient* socketClient = static_cast<SocketClient*>(attr);
    sockaddr_in hint = socketClient->getHint();

    //Connect socket with server
    int connectRes = connect(socketClient->getSockClient(), (sockaddr*)&hint, sizeof(hint));
    if(connectRes == -1) {
       cerr << "Can't connect in server!" <<endl;
       pthread_exit(NULL);
    }

    cout << "connected in server!" << endl;
    vector<uchar> buff = socketClient->getBufferImg();
    
    string str(buff.begin(), buff.end());
    
    int sendRes = send(socketClient->getSockClient(),  str.c_str(), str.size() +1, 0);
    if(sendRes == -1) {
       cout << "Could not send to server! \n";
    }
    
    close(socketClient->getSockClient());
    printf("close socket\n");
    pthread_exit(NULL);
}

void SocketClient::sendImageForApi(cv::Mat* img) { //Vai ter os dados da imagem da realsense
    cout<< "Init send image for api" << endl;

    //Init attr for thread

    std::vector<int> param(2);
    param[0] = cv::IMWRITE_JPEG_QUALITY;
    param[1] = 80;//default(95) 0-100
    cv::imencode(".jpg", *img, bufferImg, param);
    
    ///home/lukn23/TALKER-V-EYE/VisionApiTest/app/src/main/resources    (this is java resources path)
    imwrite("/home/lukn23/TALKER-V-EYE/VisionApiTest/app/src/main/resources/teste.jpg", *img);
    
    long status = pthread_create (&thread, NULL, sendMessage,(void*) this);
    if (status) {
        perror ("pthread_create") ;
        exit(1);
    }
}

void SocketClient::sendImageForApi(cv::Mat* img, int tipoIdentificacao, int alturaPxl, int larguraPxl, int alturaImg, int larguraImg) {
     heightPixel =  alturaPxl;
     widthPixel = larguraPxl;
     heightImage = alturaImg;
     widthImage = larguraImg;
     identifyType = tipoIdentificacao;
     
     imwrite("/home/lukn23/TALKER-V-EYE/VisionApiTest/app/src/main/resources/teste.jpg", *img);

     long status = pthread_create (&thread, NULL, sendMessageForJava,(void*) this);
     if (status) {
        perror ("pthread_create") ;
        exit(1);
     }    
}

void SocketClient::setBufferImg(vector<uchar> bufferImgAttr){
    bufferImg = bufferImgAttr;
}

void SocketClient::setSockClient(int sockClientAttr){
    sockClient = sockClientAttr;
}

int SocketClient::getSockClient(){
    return sockClient;
}

vector<uchar> SocketClient::getBufferImg(){
    return bufferImg;
}

sockaddr_in SocketClient::getHint(){
    return hint;
}

int SocketClient::getHeightPixel(){
    return heightPixel;
}

int SocketClient::getWidthPixel(){
    return widthPixel;
}

int SocketClient::getHeightImage(){
    return heightImage;
}

int SocketClient::getWidthImage(){
    return widthImage;
}

int SocketClient::getIdentifyType() {
    return identifyType;
}
