#include "Realsense.h"

Realsense::Realsense() {
    pipe.start();
    frame = pipe.wait_for_frames();
    
}

Realsense::~Realsense() {

}

void Realsense::read_img(){
    frame = pipe.wait_for_frames();
    cv::Mat image_aux(Size(frame.get_depth_frame().get_width(), frame.get_depth_frame().get_height()), CV_8UC3, (void*)frame.get_data(), Mat::AUTO_STEP);
    image = image_aux;
}

void Realsense::print_img(){
    int width = frame.get_depth_frame().get_width();
    int height = frame.get_depth_frame().get_height();
    
    for(int i=0; i<width; i+=10){
        for(int j=0; j<height; j+=10){
            cout << (int)image.ptr(i,j)[0] << " ";
        }
        cout << endl;
    }
    
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

int Realsense::get_color(int x, int y){
    rs2::video_frame color = frame.get_color_frame();
    color.get_data();
    
    
    return 0;
}
