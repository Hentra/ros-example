#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"
#include <stdlib.h> //For rand()

int main(int argc, char **argv){
    ros::init(argc, argv, "temperature_sensor_cpp");
    ROS_INFO("Starting temperature_sensor_cpp...");
    ros::NodeHandle nodeHandle;
    ros::Publisher tempPub = nodeHandle.advertise<sensor_msgs::Temperature>("franek/temperature", 10);
    
    ros::Rate r(1); //1Hz
    ROS_INFO("Started temperature_sensor_cpp successfully. Publishing...");
    while(ros::ok()){
        //Generate a Temperature Message
        sensor_msgs::Temperature t;
        t.header.frame_id = "franek_link";
        t.header.stamp = ros::Time::now();
        t.temperature = rand() % 30; //Random Value between 0 an 30
        t.variance = 0; //0 = unknown

        tempPub.publish(t);
        ROS_INFO("Published Temp: %f", t.temperature);

        r.sleep();
    }
    
    ros::spin();   
}