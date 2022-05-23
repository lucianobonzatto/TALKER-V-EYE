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
    ipAdrress = "127.0.0.1"; //modificar de acordo com a rede

    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT_CLIENT);
    inet_pton(AF_INET, ipAdrress.c_str(), &hint.sin_addr);

}

static void* sendMessage(void *attr) {
    cout <<"send message init" << endl;
    //uchar *charBuf = (uchar*)attr;
    /* create a vector by copying out the contents of charBuf */
    //vector<uchar> jpegData(charBuf, charBuf + len);

    SocketClient* socketClient = static_cast<SocketClient*>(attr);
    sockaddr_in hint = socketClient->getHint();

    //Connect socket with server
    int connectRes = connect(socketClient->getSockClient(), (sockaddr*)&hint, sizeof(hint));
    if(connectRes == -1) {
       cerr << "Can't connect in server!" <<endl;
       return 0;
    }
    cout << "connected in server!" << endl;
    vector<uchar> buff = socketClient->getBufferImg();
    
    string str(buff.begin(), buff.end());
    for(int i = 0; i < buff.size(); i++) {
  	int sendRes = send(socketClient->getSockClient(),  str.c_str(), str.size() +1, 0);
        if(sendRes == -1) {
           cout << "Could not send to server! \n";
        }
    }
    printf("close socket\n");
    close(socketClient->getSockClient());
    return 0;
}

void SocketClient::sendImageForApi(cv::Mat* img) { //Vai ter os dados da imagem da realsense
    cout<< "Init send image for api" << endl;

   cv::imwrite("some.jpg", *img);
   cv::imshow("some", *img);
   cv::waitKey();

    //Init attr for thread
    pthread_attr_init (&attr) ;
    pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);

   // std::vector<uchar> buff;//buffer for img
    std::vector<int> param(2);
    param[0] = cv::IMWRITE_JPEG_QUALITY;
    param[1] = 80;//default(95) 0-100
    cv::imencode(".jpg", *img, bufferImg, param);

    cout <<"finish image decode" << endl;
    long status = pthread_create (&thread, &attr, sendMessage,(void*) this);
    if (status) {
        perror ("pthread_create") ;
        exit (1) ;
    }

    pthread_attr_destroy (&attr) ;
    pthread_exit (NULL) ;
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
