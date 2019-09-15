#include "ros/ros.h"
#include "turtles/turtleQuality.h"
#include <iostream>

void setTurtleData(const turtles::turtleQuality::ConstPtr& turtleData) {
    if (turtleData->quality >= 7) {
        std::cout << "Turtle number " << turtleData->index << " has a social credit score of " << turtleData->quality << ". We should let it into the country." << '\n';
    }
}

int main(int argc, char ** argv) {
    ros::init(argc, argv, "subscriberNode");
    ros::NodeHandle node_handle;
    ros::Subscriber sub = node_handle.subscribe("turtles", 1000, setTurtleData);
    ros::spin();
}