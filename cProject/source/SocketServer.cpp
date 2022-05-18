#include "SocketServer.h"

int server_socket, client_socket, addrlen;
struct sockaddr_in address; //10.0.2.15

SocketServer::SocketServer() {
    init();
}

SocketServer::~SocketServer() {

}

void SocketServer::init() {
    this.port = 9098;
    this.addrlen = sizeof(address);
    //int valread;
    this.opt = 1;

    if ((server_socket = socket(AF_INET, SOCK_STREAM,0)) ==0) {
        perror("server socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("failure in setsockopt function");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = port;

    if(bind(server_socket, (struct sockaddr*)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("error in listen function");
        exit(EXIT_FAILURE);
    }

    pthread_attr_init (&attr) ;
    pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);
    long status = pthread_create (&thread, &attr, receive_message, (void *) "") ;
     if (status) {
        perror ("pthread_create") ;
        exit (1) ;
    }
}

void* SocketServer::receive_message(void *arg_thread) {
    while(true){
        char client_message[2000];
        if((client_socket = accept(server_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen)) <0) {
            perror("Error in accept function");
            exit(EXIT_FAILURE);
        }
        //Receive a message from client
        int read_size;
        while( (read_size = recv(client_socket , client_message , 2000 , 0)) > 0 ){
            cout << client_message << endl;
        }
        
        if(read_size == 0){
            puts("Client disconnected");
            fflush(stdout);
        }
        else if(read_size == -1){
            perror("recv failed");
        }
        close(client_socket);
    }
}
