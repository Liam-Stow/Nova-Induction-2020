#include "ros/ros.h"
#include "turtles/turtleQuality.h"
#include <iostream>

void setTurtleData(const turtles::turtleQuality::ConstPtr& turtleData) {
    if (turtleData->quality >= 7) {
        ROS_INFO("Turtle number %d has a social credit score of %d. We should let it into the country.", (int)turtleData->index, (int)turtleData->quality);
    }
}

int main(int argc, char ** argv) {
    ros::init(argc, argv, "subscriberNode");
    ros::NodeHandle node_handle;
    ros::Subscriber sub = node_handle.subscribe("turtles", 1000, setTurtleData);
    ros::spin();
}