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
    if(pin != -1){
        if(lastState == 1){
            if((clock()-timer) > TIME_DELAY){
                state = gpioRead(pin);
                lastState = state;
                if(state == 1){
                    timer = clock();
                    return 0;
                }
            }
            else
                state = 0;
        }
        else{
            state = gpioRead(pin);
            lastState = state;
            if(state == 1){
                timer = clock();
            }
        }
    }
    return state;
}
