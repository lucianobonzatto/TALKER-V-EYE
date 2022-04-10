#ifndef UNTITLED_REALSENSE_H
#define UNTITLED_REALSENSE_H

#include <librealsense2/rs.hpp>
#include <iostream>

using namespace std;

class Realsense {
private:
    rs2::pipeline p;

public:
    Realsense();
    ~Realsense();

    void readImg();

};

#endif //UNTITLED_REALSENSE_H
