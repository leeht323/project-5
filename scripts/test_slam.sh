#!/bin/sh
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/turtlebot_simulator/turtlebot_gazebo/worlds/my_world.world" &
sleep 10
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 10
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"
