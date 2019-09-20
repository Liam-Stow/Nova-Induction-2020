cmake_minimum_required(VERSION 2.8.3)
project(turtles)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  turtleQuality.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

## The catkin_package macro generates cmake config files for your package
catkin_package(CATKIN_DEPENDS message_runtime)

## Specify additional locations of header files
include_directories(${catkin_INCLUDE_DIRS})

## Declare a C++ executable
add_executable(subscriber src/subscriber.cpp)

## Add cmake target dependencies of the executable/library
add_dependencies(subscriber turtles_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(subscriber ${catkin_LIBRARIES})