#ifndef UNTITLED_REALSENSE_H
#define UNTITLED_REALSENSE_H

#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp> 
#include <iostream>

using namespace std;
using namespace cv;

class Realsense {
private:
    rs2::pipeline pipe;
    rs2::frameset frame;
//    rs2::pointcloud pointCloud;
    rs2::points points;
    Mat image;
    
public:
    Realsense();
    ~Realsense();

    void read_img();
    void print_img();
    float get_depth(int x, int y);
    Mat* get_img();
    int get_width();
    int get_height();
    
};

#endif //UNTITLED_REALSENSE_H
