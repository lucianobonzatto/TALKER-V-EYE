#include "Realsense.h"

Realsense::Realsense() {
    tryConnection();
    if(RSconnected == 1){
        pipe.start();
        frame = pipe.wait_for_frames();
    }
}

Realsense::~Realsense() {

}

int Realsense::tryConnection(){
    rs2::context ctx;
    if (ctx.query_all_sensors().size() == 0){
        cout << "No Realsense detected" << endl;
        RSconnected = 0;
        return 0;
    }

    cout << "Realsense conected" << endl;
    RSconnected = 1;
    return 1;
}

void Realsense::read_img(){
//    tryConnection();
//    if(RSconnected == 0){
//        return;
//    }

    //read rs informations
//    frame = pipe.wait_for_frames();
    pipe.poll_for_frames(&frame);
    
    //remap the image
    int w = frame.get_color_frame().get_width();
    int h = frame.get_color_frame().get_height();
    cv::Mat image_aux(Size(w, h), CV_8UC3, (void*)frame.get_color_frame().get_data(), Mat::AUTO_STEP);
    cvtColor(image_aux, image, COLOR_BGR2RGB);
    
    //remap the pointClound
    rs2::pointcloud pointCloud;
    points = pointCloud.calculate(frame.get_depth_frame());
}

void Realsense::print_img(){
    int width = frame.get_depth_frame().get_width();
    int height = frame.get_depth_frame().get_height();

    for(int i=0; i<width; i+=10){
        for(int j=0; j<height; j+=10){
            cout << (int) *image.ptr(i,j) << " ";
        }
        cout << endl;
    }
    
}

void Realsense::print_points(){
    int min = 0;
    const rs2::vertex* teste = points.get_vertices();

    for(int i=0; i< points.size(); i++){
        if(teste[min].x == 0){
            min = i;
        }
        if(teste[i].x > teste[min].x){
            min = i;
        }
    }
    cout << teste[min].x << endl;
}

int Realsense::get_depth_width(){
    return frame.get_depth_frame().get_width();
}

int Realsense::get_depth_height(){
    return frame.get_depth_frame().get_height();
}

int Realsense::get_img_width(){
    return frame.get_color_frame().get_width();
}

int Realsense::get_img_height(){
    return frame.get_color_frame().get_height();
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

Mat* Realsense::get_img(){
    return &image;
}

rs2::points* Realsense::getPoints(){
    return &points;
}
