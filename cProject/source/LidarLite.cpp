#include "LidarLite.h"

LidarLite::LidarLite() {
    sensor.i2c_init();
    sensor.configure(0);
}

LidarLite::~LidarLite() {

}

float LidarLite::getDistance(){
    sensor.takeRange();
    return ((float)sensor.readDistance()/100);
}
