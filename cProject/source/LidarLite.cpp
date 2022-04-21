#include "LidarLite.h"

LidarLite::LidarLite() {
    sensor.i2c_init();
    sensor.configure(0);
}

LidarLite::~LidarLite() {

}

int LidarLite::getDistance(){
    sensor.takeRange();
    return sensor.readDistance();
}
