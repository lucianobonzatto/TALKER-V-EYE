#include "Realsense.h"

Realsense::Realsense() {
    pipe.start();
    frame = pipe.wait_for_frames();
    
    
    
}

Realsense::~Realsense() {

}

void Realsense::read_img(){
    frame = pipe.wait_for_frames();
}

int Realsense::get_width(){
    return frame.get_depth_frame().get_width();
}

int Realsense::get_height(){
    return frame.get_depth_frame().get_height();
}

float Realsense::get_depth(int x, int y){
    rs2::depth_frame depth = frame.get_depth_frame();
    int width = depth.get_width();
    int height = depth.get_height();
    if(y < 0 || width < x)
        return -1;
    if(x < 0 || height < y)
        return -1;
    return depth.get_distance(x, y);
}
