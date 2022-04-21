#ifndef UNTITLED_PROCESSADORA_H
#define UNTITLED_PROCESSADORA_H

#include "Realsense.h"
#include "LidarLite.h"
#include <iostream>

using namespace std;

class Processadora {
private:
    Realsense rs_sensor;
    LidarLite ll_sensor;

public:
    Processadora();
    ~Processadora();


};

#endif //UNTITLED_PROCESSADORA_H
