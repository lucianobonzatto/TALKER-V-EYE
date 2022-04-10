#include "Processadora.h"

Processadora::Processadora() {
    cout << "Processadora costruct" << endl;
    rs_sensor.readImg();
}

Processadora::~Processadora() {

}
