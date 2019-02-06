#include "ros/ros.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "hello_world_cpp", ros::init_options::AnonymousName);
    ros::NodeHandle nodeHandle;
    ROS_INFO("Hello from Cpp-Node!");
    ros::spin();   
}