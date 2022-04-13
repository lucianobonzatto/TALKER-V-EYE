#ifndef UNTITLED_REALSENSE_H
#define UNTITLED_REALSENSE_H

#include <librealsense2/rs.hpp>
#include <iostream>

using namespace std;

class Realsense {
private:
    rs2::pipeline pipe;
    rs2::frameset frame;
    
    
public:
    Realsense();
    ~Realsense();

    void read_img();
    float get_depth(int x, int y);
    int get_width();
    int get_height();
    
    
};

#endif //UNTITLED_REALSENSE_H
