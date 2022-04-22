#include "MotorVib.h"

MotorVib::MotorVib() {
    intensity = 0;
    pin = -1;                //Valor -1 indica nenhum pino setado.
}

MotorVib::MotorVib(short int pinP, short int intensityP) {
    pin = pinP;
    intensity = intensityP;
}

MotorVib::~MotorVib() {

}

void setIntensity(short int intensityP){
    intensity = intensityP;
}

short int getIntensity(){
    return intensity;
}