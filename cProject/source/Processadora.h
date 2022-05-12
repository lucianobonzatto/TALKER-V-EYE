#ifndef UNTITLED_PROCESSADORA_H
#define UNTITLED_PROCESSADORA_H

#include "Realsense.h"
#include "LidarLite.h"
#include "MotorVib.h"
#include <iostream>
#include <unistd.h>

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

    void printRSDepth();
    void printLLDepth();
    void testeMotor();
public:
    Processadora();
    ~Processadora();
};

#endif //UNTITLED_PROCESSADORA_H
