#ifndef UNTITLED_SOCKET_CLIENT_H
#define UNTITLED_SOCKET_CLIENT_H

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
#include <opencv2/opencv.hpp> 

using namespace std;

class SocketClient {
private:
    int port;
    string ipAdrress;
    sockaddr_in hint;
    pthread_t thread;
    pthread_attr_t attr;
    string data;
    int sockClient;

private:
    void *sendMessage(void* attr);

public:
    SocketClient();
    ~SocketClient();
    void init();
    void sendImageForApi(Mat* img);
};

#endif //UNTITLED_SOCKET_CLIENT_H
