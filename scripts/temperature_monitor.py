#! /usr/bin/env python
import rospy, std_msgs.msg
from sensor_msgs.msg import Temperature

pub = rospy.Publisher('henri/temp_average', Temperature, queue_size=10)
average = 0
variance = 0

def callback(data):
    global average, variance, pub
    rospy.loginfo('Temperature Received: %f', data.temperature)
    average = (average + data.temperature)/2
    variance = (variance + data.variance)/2

    t = Temperature()

    h = std_msgs.msg.Header()
    h.stamp = rospy.Time.now()
    
    t.header = h
    t.temperature = average
    t.variance = variance
    
    pub.publish(t)

def listen_temp():
    rospy.init_node('temperature_monitor_py', anonymous=True)
    rospy.Subscriber('henri/temperature', Temperature, callback)
    rospy.spin()

if __name__ == '__main__':
    listen_temp()
