#include "MotorVib.h"

MotorVib::MotorVib() {
    intensity = 0;
    pin = -1;                //Valor -1 indica nenhum pino setado.
}

MotorVib::MotorVib(short int pinP, short int intensityP) {
    pin = pinP;
    intensity = intensityP;
    gpioSetMode(pin, PI_OUTPUT);
}

MotorVib::~MotorVib() {

}

void MotorVib::setIntensity(short int intensityP){
    intensity = intensityP;
    gpioPWM(pin, intensity);
}

void MotorVib::setPin(short int pinP){
    pin = pinP;
    gpioSetMode(pin, PI_OUTPUT);
}

short int MotorVib::getIntensity(){
    return intensity;
}
