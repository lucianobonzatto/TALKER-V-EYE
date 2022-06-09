#include "Configuracao.h"

Configuracao::Configuracao() {
    /*ABRIR ARQUIVO DE CONFIGURACAO - PENDENTE*/
    //Config padrao
    alturaRealsense = 130;
    larguraBraco = 20;
    profundidadeMaxima = 2;
}

float Configuracao::getAlturaRealsense(){
    if(socketServer.messageReceived()){
        converteDados(socketServer.getMessage());
    }

    return alturaRealsense;
}

float Configuracao::getLarguraBraco(){
    if(socketServer.messageReceived()){
        converteDados(socketServer.getMessage());
    }

    return larguraBraco;
}

float Configuracao::getProfundidadeMaxima(){
    if(socketServer.messageReceived()){
        converteDados(socketServer.getMessage());
    }
    return profundidadeMaxima;
}

void Configuracao::converteDados(char* dados){
    //XUNXO. Formato dos dados = "AAA,LL,P" -> Contém 8 caracteres.
    char altura[3];
    altura[0] = dados[0];
    altura[1] = dados[1];
    altura[2] = dados[2];
    alturaRealsense = atof(altura);

    char largura_braco[2];
    largura_braco[0] = dados[4];
    largura_braco[1] = dados[5];
    larguraBraco = atof(largura_braco);

    char profundidade_max[1];
    profundidade_max[0] = dados[7];
    profundidadeMaxima = atof(profundidade_max);
}

Configuracao::~Configuracao() {

}
