#include <iostream>
#include "Processadora.h"

int main() {
    std::cout << "Hello" << std::endl;
    if(gpioInitialise() < 0){
        std::cout << "Erro ao inicializar PIGPIO." << std::endl;
        return 0;
    }


    Processadora teste;
    teste.loop();

    std::cout << "Bie" << std::endl;
    gpioTerminate();
    return 0;
}
