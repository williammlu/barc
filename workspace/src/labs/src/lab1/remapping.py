#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def callback_function(data):
    #FILL IN HERE
    global pubname, msg
    msg.linear.x = -data.linear.x
    msg.angular.z = -data.angular.z
    pubname.publish(msg)


def subscriber_name():
    # Initialize node
    rospy.init_node('subscriber_name', anonymous=True)
    global pubname, msg
    msg = Twist()
    pubname = rospy.Publisher('remapped_topic_name', Twist, queue_size=10)

    rospy.Subscriber('turtle1/cmd_vel', Twist, callback_function)
    rospy.Rate(10)
    rospy.spin()


if __name__ == '__main__':
    try:
        subscriber_name()
    except rospy.ROSInterruptException:
        pass
