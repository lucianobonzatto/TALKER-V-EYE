#include "MotorVib.h"

MotorVib::MotorVib() {
    this->intensity = 0;
    this->pin = -1;                //Valor -1 indica nenhum pino setado.
}

MotorVib::MotorVib(short int pin, short int intensity) {
    this->pin = pin;
    this->intensity = intensity;
}

MotorVib::~MotorVib() {

}

void setIntensity(short int intensity){
    this->intensity = intensity;
}

short int getIntensity(){
    return this->intensity;
}