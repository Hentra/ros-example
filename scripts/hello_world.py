#! /usr/bin/env python

import rospy

def example():
    rospy.init_node('example')
    rospy.loginfo('Hello World')
    rospy.spin()

if __name__ == '__main__':
    try: 
        example()
    except rospy.ROSInterruptException:
        pass
