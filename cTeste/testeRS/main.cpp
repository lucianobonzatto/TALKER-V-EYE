#include <iostream>
#include <librealsense2/rs.hpp>

using namespace std;
int main(int argc, char * argv[])
{
	rs2::pipeline p;
	cout << "oi" << endl;
	p.start();
	while (true)
	{
		// Block program until frames arrive
		rs2::frameset frames = p.wait_for_frames();
		// Try to get a frame of a depth image
		rs2::depth_frame depth = frames.get_depth_frame();
		// Get the depth frame's dimensions
		auto width = depth.get_width();
		auto height = depth.get_height();
		// Query the distance from the camera to the object in the center of the i>
		float dist_to_center = depth.get_distance(width / 2, height / 2);
		// Print the distance
		std::cout << "The camera is facing an object " << dist_to_center << endl;
	}
	return EXIT_SUCCESS;

}
