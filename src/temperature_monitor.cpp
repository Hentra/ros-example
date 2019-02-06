#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"

ros::Publisher average_pub;
float average;
float variance;


void temp_callback(const sensor_msgs::TemperatureConstPtr& temp) {
    ROS_INFO("Temperature Received: %f", temp->temperature);
    average = (average + temp->temperature) / 2; //Floading Avarage
    variance += temp->variance; //Highest Variance

    sensor_msgs::Temperature avTemp;
    avTemp.header.stamp = ros::Time::now();
    avTemp.temperature = average;
    avTemp.variance = variance;

    average_pub.publish(avTemp);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "temperature_monitor_cpp", ros::init_options::AnonymousName);
    ROS_INFO("Starting temperature_monitor_cpp...");
    ros::NodeHandle nodeHandle;
    average = 0;
    variance = 0;
    average_pub = nodeHandle.advertise<sensor_msgs::Temperature>("franek/temp_average", 10);
    ros::Subscriber tempSub = nodeHandle.subscribe("franek/temperature", 10, temp_callback);

    ROS_INFO("Started temperature_monitore_cpp successfully. Listening...");

    ros::spin();   
}

