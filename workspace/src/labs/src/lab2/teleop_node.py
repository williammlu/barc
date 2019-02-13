#!/usr/bin/env python

import rospy
import time
from barc.msg import ECU
from labs.msg import Z_DynBkMdl 
from geometry_msgs.msg import Twist
	
# initialize state
x = 0
y = 0
v_x = 0
v_y = 0

accel = 0
ang_accel = 0
	
# ecu command update
def twist_callback(twist):
    print "twist callback~!!!"
    global accel, ang_accel
    accel = twist.linear.y
    ang_accel = twist.angular.y


# controller node
def controller():
	# initialize node
	rospy.init_node('controller', anonymous=True)
	
	rospy.Subscriber('/cmd_vel', Twist, twist_callback)
	# topic subscriptions / publications
	state_pub = rospy.Publisher('ecu', ECU, queue_size = 10)
	
	# set node rate
	loop_rate = 50
	dt = 1.0 / loop_rate
	rate = rospy.Rate(loop_rate)
	t0 = time.time()
	
	
	
	while not rospy.is_shutdown():
	
	        global accel, ang_accel
		# publish information
	 	state_pub.publish( ECU(accel, ang_accel))
	
		# wait
		rate.sleep()
	
if __name__ == '__main__':
	try:
		controller()
	except rospy.ROSInterruptException:
		pass
