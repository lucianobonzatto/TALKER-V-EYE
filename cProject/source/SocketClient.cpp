#include "SocketClient.h"

SocketClient::SocketClient() {
    init();
}

SocketClient::~SocketClient() {

}

void SocketClient::init() {
    //Create socket
    this.sockClient = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        cerr << "Can't create a socket!";
        return 1;
    }

    //Configure socket
    port = 9090; //port created in Java side
    ipAdrress = "192.168.1.74"; //modificar de acordo com a rede

    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAdrress.c_str(), &hint.sin_addr);

    //Connect socket with server
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if(connectRes == -1){
        cerr << "Can't connect in server!";
        return 1;
    }
    printf("connected in server\n");
}

void* SocketClient::sendMessage(void* attr) {
    int sendRes = send(this.sockClient, (string) attr.c_str(), (string) attr.size() + 1, 0);
    if(sendRes == -1) {
        cout << "Could not send to server! \n";
    }
    printf("close socket\n");
    close(sock);
}

void* SocketClient::sendImageForApi(Mat* img) { //Vai ter os dados da imagem da realsense
    //Init attr for thread
    pthread_attr_init (&attr) ;
    pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);
   
    //Talvez fazer a tardução do parametro de sendImageForApi para string (data)
    long status = pthread_create (&thread, &attr, sendMessage, (void*) data) ;
     if (status) {
        perror ("pthread_create") ;
        exit (1) ;
     }

    pthread_attr_destroy (&attr) ;
    pthread_exit (NULL) ;
}

