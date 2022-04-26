#ifndef UNTITLED_LIDARLITE_H
#define UNTITLED_LIDARLITE_H

#include "lidarlite_v3.h"


class LidarLite {
private:
    LIDARLite_v3 sensor;

public:
    LidarLite();
    ~LidarLite();

    float getDistance();
};

#endif //UNTITLED_LIDARLITE_H
