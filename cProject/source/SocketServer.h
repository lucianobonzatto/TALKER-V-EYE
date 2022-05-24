#ifndef UNTITLED_SOCKET_SERVER_H
#define UNTITLED_SOCKET_SERVER_H

//for socket TCP/IP
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

//for image
#include <fstream>
#include <sstream>

//for thread
#include <pthread.h>

#define PORT 9098

using namespace std;

class SocketServer {
private:
    int serverSocket;
    int clientSocket;
    int addrlen;
    struct sockaddr_in address;
    int port;
    int opt;
    pthread_t thread;
    pthread_attr_t attr;
    bool msgReceived;
    char* message;

public:
    SocketServer();
    ~SocketServer();
    void init();
    void setMessage(char* msg);
    int getServerSocket();
    int getClientSocket();
    int getAddrlen();
    char* getMessage();
    bool messageReceived();
    struct sockaddr_in getAddress();
};

#endif //UNTITLED_SOCKET_SERVER_H
