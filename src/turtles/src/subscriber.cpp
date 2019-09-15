#include "ros/ros.h"
#include "turtles/turtleQuality.h"

int turtleQuality;
int turtleIndex;

void setTurtleData(const turtles::turtleQuality::ConstPtr& turtleData) {
    turtleIndex = turtleData->index;
    turtleQuality = turtleData->quality;
}

int main(int argc, char ** argv) {
    ros::init(argc, argv, "subscriberNode");
    ros::NodeHandle node_handle;
    
    ros::Subscriber sub = node_handle.subscribe("turtles", 1000, setTurtleData);

    ros::spin();
}