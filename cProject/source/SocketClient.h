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

#define PORT_CLIENT 9090

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
    vector<uchar> bufferImg;

public:
    SocketClient();
    ~SocketClient();
    void init();
    void sendImageForApi(cv::Mat* img);
    void setBufferImg(vector<uchar> bufferImgAttr);
    void setSockClient(int sockClientAttr);
    int getSockClient();
    sockaddr_in getHint();
    vector<uchar> getBufferImg();
};

#endif //UNTITLED_SOCKET_CLIENT_H
