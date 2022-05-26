#ifndef UNTITLED_PROCESSADORA_H
#define UNTITLED_PROCESSADORA_H

#include "Realsense.h"
#include "LidarLite.h"
#include "MotorVib.h"
#include <iostream>
#include <unistd.h>
#include "SocketClient.h"
#include "Configuracao.h"

#define INTERV_CHAO 0.40
#define INTERV_ANALISE 20
#define INTERV_OBSTACULO 0.30
#define MIN_PONTOS_QUADRANTE 500
//#define DIST_MAX_RS 3
//#define DIST_MIN_RS 0.3
#define DIST_MAX_LL 80
#define DIST_MIN_LL 20

using namespace std;

class Processadora {
private:
    Realsense rs_sensor;
    LidarLite ll_sensor;
    MotorVib m1;
    MotorVib m2;
    MotorVib m3;
    MotorVib m4;
    MotorVib mp;
//    SocketClient sockClient;
    Configuracao config;
//    float alturaRealsense;

    void printRSDepth();
    void printLLDepth();
    void testeMotor();
    void detectaObstaculo();
    void detectaLidar();
    std::pair<int,int> convertePontoPixel(float x, float y, float z);
    int convertePontoQuadrante(float x, float y);
    float calculaDistancia(float x, float y, float z);
    int convertePixelQuadrante(std::pair<int,int> pixel);
    int converteDistanciaIntensidade_rs(float distancia);
    int converteDistanciaIntensidade_ll(float distancia);

public:
    Processadora();
    ~Processadora();
};

#endif //UNTITLED_PROCESSADORA_H
