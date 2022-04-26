#ifndef UNTITLED_MOTORVIB_H
#define UNTITLED_MOTORVIB_H
#include <pigpio.h>

class MotorVib {
private:
    short int intensity;
    short int pin;

public:
    MotorVib();
    MotorVib(short int pinP, short int intensityP = 0);
    ~MotorVib();

    void setIntensity(short int intensityP);
    short int getIntensity();
    void setPin(short int pinP);
};

#endif //UNTITLED_MOTORVIB_H
