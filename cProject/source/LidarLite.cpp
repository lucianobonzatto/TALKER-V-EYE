#include "LidarLite.h"

LidarLite::LidarLite() {
    sensor.i2c_init();
    tryConnection();
}

LidarLite::~LidarLite() {

}

int LidarLite::tryConnection(){
    if(sensor.i2c_connect()){
        std::cout << "No LidarLite detected" << std::endl;
        LLconnected = 0;
        return 0;
    }

    std::cout << "LidarLite connected" << std::endl;
    LLconnected = 1;
    sensor.configure(1);
    return 1;
}

float LidarLite::getDistance(){
    tryConnection();
    if(LLconnected == 0){
        return -1;
    }

    sensor.takeRange();
    while(1){
        if(sensor.getBusyFlag() == 0x00)
            return ((float)sensor.readDistance());
    }
}
