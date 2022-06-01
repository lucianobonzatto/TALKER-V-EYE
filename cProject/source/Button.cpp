#include "Button.h"

Button::Button() {
    pin = -1;                //Valor -1 indica nenhum pino setado.
    lastState = 0;
    timer = clock();
}

Button::~Button() {

}

void Button::setPin(short int pinP){
    pin = pinP;
    gpioSetMode(pin, PI_INPUT);
}

int Button::getState(){
    int state = 0;
    if(pin == -1){
        return 0;
    }
//    std::cout << "\tin -> lastState: " << lastState << " state: " << gpioRead(pin) << std::endl;
    if(lastState == 0){
        state = gpioRead(pin);
        lastState = state;
        if(state == 1)
            timer = clock();
//        std::cout << "\tout 1 -> lastState: " << lastState << " state: " << gpioRead(pin) << std::endl;
        return state;
    }

    if((clock()-timer) > TIME_DELAY){
        state = gpioRead(pin);
        lastState = state;
        if(state == 1){
            timer = clock();
//            std::cout << "\tout 2 -> lastState: " << lastState << " state: " << gpioRead(pin) << std::endl;
            return 0;
        }
    }
    else
        state = 0;
//    std::cout << "\tout 3 -> lastState: " << lastState << " state: " << gpioRead(pin) << std::endl;
    return state;
}
