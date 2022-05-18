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


using namespace std;
int sock;
string data;

void *send_message(void* attr) {
    int sendRes = send(sock, data.c_str(), data.size() + 1, 0);
    if(sendRes == -1) {
        cout << "Could not send to server! \n";
    }

    printf("close socket\n");
    close(sock);
}

int main() {

    int port;
    string ipAdrress;
    sockaddr_in hint;
    pthread_t thread;
    pthread_attr_t attr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        cerr << "Can't create a socket!";
        return 1;
    }

    port = 9090; //port created in Java side
    //string ipAdrress = "192.168.1.82"; //repetidor de sinal 5G
    ipAdrress = "192.168.1.74";

    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAdrress.c_str(), &hint.sin_addr);

    
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if(connectRes == -1){
        cerr << "Can't connect in server!";
        return 1;
    }

    printf("connected in server\n");

    //Lendo o arquivo
    /*ifstream ifs("center_city.JPG", ios::in | ios::binary); // input file
    ostringstream oss; // output to string

    int len;
    char buf[1024];
    while((len = ifs.readsome(buf, 1024)) > 0)
    {
        oss.write(buf, len);
    }
    printf("finish reading file\n"); 

    string data = oss.str(); // get string data out of stream */

    pthread_attr_init (&attr) ;
    pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);

    long status = pthread_create (&thread, &attr, send_message, (void*) data) ;
     if (status) {
        perror ("pthread_create") ;
        exit (1) ;
     }

    return 0;
}

/*  LEITURA DO TECLADO 
    char buf[4096];
    string userInput;

    do{
        cout << " > :";
        getline(cin, userInput);

        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if(sendRes == -1) {
            cout << "Could not send to server! \n";
            continue;
        }
        
    }while(true); */
