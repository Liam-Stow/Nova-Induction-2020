#!/usr/bin/env python

"""Generates and publishes turtles.

Date last updated: 15/9/19 by Liam Stow

Purpose: Completes the software induction task for 2019/2020
Subscribed topic/s: N/A
Published topic/s: "turtles"
"""

import rospy
import random
from turtles.msg import turtleQuality

if __name__ == "__main__":
    
    pub = rospy.Publisher("turtles", turtleQuality, queue_size=10)
    rospy.init_node('publisherNode')
    
    # Loop at 5Hz
    rate = rospy.Rate(5)

    # Count the turtles as we go
    index = 0
    while not rospy.is_shutdown():

        # Make a random turtle
        turtle_msg = turtleQuality()
        turtle_msg.index = index
        turtle_msg.quality = random.randint(1, 10)

        # Publish the turtle
        pub.publish(turtle_msg)

        # Wait a moment in each loop interation
        index += 1
        rate.sleep()