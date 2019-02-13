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

	 	
# Insert your PID longitudinal controller here: since you are asked to do longitudinal control,  the steering angle d_f can always be set to zero. Therefore, the control output of your controller is essentially longitudinal acceleration acc.
# ==========PID longitudinal controller=========#
class PID():
	def __init__(self, kp=1, ki=1, kd=1):
		self.kp = kp
		self.ki = ki
		self.kd = kd
                self.int = 0
                self.prev_err = 0
	
	def acc_calculate(self, speed_reference, speed_current):
                error = speed_reference - speed_current
                self.int += error/50.0
                der = self.prev_err - error
                self.prev_err = error
	 	acc = self.kp * error + self.ki * self.int + self.kd * der

	 	return acc
	
# ==========end of the controller==============#
	
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
	
	# set initial conditions 
	d_f = 0
	acc = 0
	
	# reference speed 
	v_ref = 8 # reference speed is 8 m/s
	
	# Initialize the PID controller with your tuned gains
	PID_control = PID(kp=5, ki=0.5, kd=0.5) # may tune this TODO
	
	while not rospy.is_shutdown():
		# acceleration calculated from PID controller.
	 	acc = PID_control.acc_calculate(v_ref, v_x)
	 
	 	# steering angle
	 	d_f = 0.0
	
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
