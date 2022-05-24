#ifndef UNTITLED_CONFIGURACAO_H
#define UNTITLED_CONFIGURACAO_H

#include "SocketServer.h"

class Configuracao {
private:
    float alturaRealsense;
    float larguraBraco;
    float profundidadeMaxima;
    SocketServer socketServer;

public:
    Configuracao();
    float getAlturaRealsense();
    float getLarguraBraco();
    float getProfundidadeMaxima();
    void converteDados(char* dados);
    ~Configuracao();

};

#endif //UNTITLED_CONFIGURACAO_H
