#include "Processadora.h"

Processadora::Processadora() {
    while(1){
        usleep(20000);
        rs_sensor.read_img();
        rs_sensor.print_points();
        //printRSDepth();
        //rs_sensor.print_img();
    }
}

Processadora::~Processadora() {

}

void Processadora::printRSDepth() {
    int width, height, i_aux = -1, j_aux = -1;
    float men_dist, at_dist;

    rs_sensor.read_img();
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
    std::cout << "depth(" << i_aux << ")(" << j_aux << ")\t->\t" << men_dist << std::endl;
}

void Processadora::printLLDepth() {
    std::cout << "\t\t" << "lidar\t->\t" << ll_sensor.getDistance() << std::endl;
}
