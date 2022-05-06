#ifndef UNTITLED_LIDARLITE_H
#define UNTITLED_LIDARLITE_H

#include "lidarlite_v3.h"
#include <iostream>

class LidarLite {
private:
    int LLconnected;
    LIDARLite_v3 sensor;

public:
    LidarLite();
    ~LidarLite();

    float getDistance();
    int tryConnection();
};

#endif //UNTITLED_LIDARLITE_H
