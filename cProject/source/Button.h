#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H

#include <iostream>
#include <pigpio.h>
#include <time.h>

#define TIME_DELAY 1000

class Button {
private:
    short int pin;
    int lastState;
    clock_t timer;

public:
    Button();
    ~Button();

    void setPin(short int pinP);
    int getState();
};

#endif //UNTITLED_BUTTON_H
