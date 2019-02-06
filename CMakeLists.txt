cmake_minimum_required(VERSION 2.8.3)
project(example)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy)

## Declare a catkin package
catkin_package()


include_directories(include ${catkin_INCLUDE_DIRS})

##For 'Hello_world.cpp'
add_executable(hello_world_cpp src/hello_world.cpp)
target_link_libraries(hello_world_cpp ${catkin_LIBRARIES})

##For 'temperature_sensor.cpp'
add_executable(temperature_sensor_cpp src/temperature_sensor.cpp)
target_link_libraries(temperature_sensor_cpp ${catkin_LIBRARIES})

##For 'temperature_monitor.cpp'
add_executable(temperature_monitor_cpp src/temperature_monitor.cpp)
target_link_libraries(temperature_monitor_cpp ${catkin_LIBRARIES})