#! /usr/bin/env python
import rospy, random, std_msgs.msg
from sensor_msgs.msg import Temperature

def publish_temp():
        pub = rospy.Publisher('henri/temperature', Temperature, queue_size=10)
        rospy.init_node('temperature_sensor_py', anonymous=True)
        rate = rospy.Rate(1)
        while not rospy.is_shutdown():
            t = Temperature()

            h = std_msgs.msg.Header()
            h.stamp = rospy.Time.now()
            h.frame_id = 'henri_link'

            t.header = h
            t.temperature = random.uniform(0.0, 30.0)
            t.variance = 0

            pub.publish(t)
            rospy.loginfo('Published Temp: %f', t.temperature)
            rate.sleep()

if __name__ == '__main__':
        try:
            publish_temp()
        except rospy.ROSInterruptException:
            pass
