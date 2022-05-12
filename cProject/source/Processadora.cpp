#include "Processadora.h"

Processadora::Processadora() {
    m1.setPin(14);
    m2.setPin(15);
    m3.setPin(23);
    m4.setPin(24);

    mp.setPin(17);

    while(1){
//        usleep(20000);

        std::cout << endl << "============================================================" << endl;
//        testeMotor();
        std::cout << "\tlidar\t\t->\t" << ll_sensor.getDistance() << std::endl;

        rs_sensor.read_img();
        ////rs_sensor.print_points();
        printRSDepth();
        //rs_sensor.print_img();
    }
}

Processadora::~Processadora() {

}

void Processadora::printRSDepth() {
    int width, height, i_aux = -1, j_aux = -1;
    float men_dist, at_dist;

//    rs_sensor.read_img();
    width = rs_sensor.get_width();
    height = rs_sensor.get_height();
    men_dist = 10000;

    for(int i=0; i<width; i+=10){
        for(int j=0; j<height; j+=10){
            at_dist = rs_sensor.get_depth(i, j);
            if(at_dist > 0 && men_dist > at_dist){
                men_dist = at_dist;
                i_aux = i;
                j_aux = j;
            }
        }
    }
    std::cout << "\tdepth(" << i_aux << ")(" << j_aux << ")\t->\t" << men_dist << std::endl;
}

void Processadora::printLLDepth() {
    std::cout << "\t\t" << "lidar\t->\t" << ll_sensor.getDistance() << std::endl;
}

void Processadora::testeMotor() {
    static int intensidade = 50;
    static int msel = 0;

    intensidade+=3;
    if(intensidade > 255){
        intensidade = 0;
        msel = (msel+1)%5;
    }

    switch(msel){
    case 0:
        m4.setIntensity(intensidade);
        m3.setIntensity(0);
        m2.setIntensity(0);
        m1.setIntensity(0);
        mp.setIntensity(0);
        break;
    case 1:
        m4.setIntensity(0);
        m3.setIntensity(intensidade);
        m2.setIntensity(0);
        m1.setIntensity(0);
        mp.setIntensity(0);
        break;
    case 2:
        m4.setIntensity(0);
        m3.setIntensity(0);
        m2.setIntensity(intensidade);
        m1.setIntensity(0);
        mp.setIntensity(0);
        break;
    case 3:
        m4.setIntensity(0);
        m3.setIntensity(0);
        m2.setIntensity(0);
        m1.setIntensity(intensidade);
        mp.setIntensity(0);
        break;
    case 4:
        m4.setIntensity(0);
        m3.setIntensity(0);
        m2.setIntensity(0);
        m1.setIntensity(0);
        mp.setIntensity(intensidade);
        break;

    }
//    std::cout << "\tintensidade\t->\t" << intensidade << "\tmotor\t->\t" << msel << std::endl;
}
