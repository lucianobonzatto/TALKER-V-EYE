#include <iostream>
#include <pigpio.h>
#define PINO 15

/*gcc -Wall -pthread -o testePig testePig.c -lpigpio -lrt*/

int main(){
    if(gpioInitialise() < 0){
        std::cout << "Erro ao inicializar a biblioteca." << std::endl;
        exit(1);
    }


    /*  ===== Resuminho Biblioteca =====
        gpioSetMode(GPIO, MODO)
            PI_INPUT -> Seta PINO como uma entrada.
            PI_OUTPUT-> Seta PINO como uma saida.
            PI_ALT0  -> Seta PINO como modo alternativo.*/

    /*  Funções para escrita/leitura nos GPIOs:
        gpioRead    
        gpioWrite */

    /*  PWM
        gpioPWM(GPIO, cicloTrabalho)    
            GPIO -> 0-31
            Equivalente ao analogWrite do arduino. Também trabalha no intervalo 0-255.
            Retorna 0 se deu tudo certo.
    */

    /*Em aproximadamente 5 segundos o LED vai do menor para o meior brilho.*/
    gpioSetMode(PINO, PI_OUTPUT);
    int intensidade = 0;
    while(1){
        if(intensidade < 255)
            intensidade ++;
        else
            intensidade = 0;

        gpioPWM(PINO, intensidade);
//        sleep(20);
    }
    gpioTerminate();
    return 0;
}

/*Usar a função gpioTerminate(void), ela encerra a biblioteca, liberando memória e encerra todas as threads em execução*/
