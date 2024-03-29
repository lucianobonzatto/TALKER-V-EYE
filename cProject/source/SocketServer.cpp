#include "SocketServer.h"

SocketServer::SocketServer() {
    init();
}

SocketServer::~SocketServer() {

}

static void* receive_message(void *arg_thread) {
// cout << "in receive_message" << endl;
 SocketServer* socketServer = static_cast<SocketServer*>(arg_thread);
 while(true){
        char client_message[2000];
        int client_socket;
        struct sockaddr_in addr = socketServer->getAddress();

        int addrlen = socketServer->getAddrlen();
        if((client_socket = accept(socketServer->getServerSocket(), (struct sockaddr*)&addr, (socklen_t*)&addrlen)) <0) {
//            perror("Error in accept function");
            exit(EXIT_FAILURE);
        }
//        cout << "message received from client" << endl;
        //Receive a message from client
        int read_size;
        while( (read_size = recv(client_socket , client_message , 2000 , 0)) > 0 ){
//            cout << "msg -> " << client_message << endl;
            socketServer->setMessage(client_message);
        }

        if(read_size == 0){
//            puts("Client disconnected");
            fflush(stdout);
        }
        else if(read_size == -1){
            perror("recv failed");
        }

        close(client_socket);
    }
}

void SocketServer::init() {
    port = 9098;
    addrlen = sizeof(address);
    //int valread;
    opt = 1;
    msgReceived = false;
    message = new char[2000];

    if ((serverSocket = socket(AF_INET, SOCK_STREAM,0)) ==0) {
        perror("server socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("failure in setsockopt function");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = inet_addr("10.0.0.101");
    address.sin_addr.s_addr = inet_addr("192.168.0.27");
//    address.sin_addr.s_addr = inet_addr("192.168.43.130");
    address.sin_port = htons(PORT);

    if(bind(serverSocket, (struct sockaddr*)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 3) < 0) {
        perror("error in listen function");
        exit(EXIT_FAILURE);
    }

    cout << "server socket created" << endl;

    long status = pthread_create (&thread, NULL, receive_message, (void *) this) ;
     if (status) {
        perror ("pthread_create") ;
        exit (1) ;
    }
}

void SocketServer::setMessage(char* msg){
    msgReceived = true;
    for(int i = 0; i < 2000; i++){  //JEITO HORRIVEL DE COPIAR VETOR DE CHAR!
       message[i] = msg[i];
    }
}

char* SocketServer::getMessage(){
    msgReceived = false;
    return message;
}

bool SocketServer::messageReceived(){
    return msgReceived;
}


int SocketServer::getServerSocket(){
   return serverSocket;
}

int SocketServer::getClientSocket(){
   return clientSocket;
}


int SocketServer::getAddrlen() {
   return addrlen;
}

struct sockaddr_in SocketServer::getAddress(){
   return address;
}

