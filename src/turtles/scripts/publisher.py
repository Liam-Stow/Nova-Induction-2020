#!/usr/bin/env python

"""Does a thing.

More stuff.
"""

import rospy
import random
from turtles.msg import turtleQuality

if __name__ == "__main__":
    pub = rospy.Publisher("turtles", turtleQuality)
    rospy.init_node('publisherNode')
    rate = rospy.Rate(5)
    index = 0
    while not rospy.is_shutdown():
        turtle_msg = turtleQuality()
        turtle_msg.index = index
        turtle_msg.quality = random.randint(1, 10)
        pub.publish(turtle_msg)
        index += 1
        rate.sleep()