#include "LidarLite.h"

LidarLite::LidarLite() {
    sensor.i2c_init();
    sensor.configure(1);
}

LidarLite::~LidarLite() {

}

float LidarLite::getDistance(){
    sensor.takeRange();
    while(1){
        if(sensor.getBusyFlag() == 0x00)
            return ((float)sensor.readDistance());
    }
}
