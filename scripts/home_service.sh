#!/bin/sh


path_catkin_ws="/home/workspace/catkin_ws"

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/turtlebot_simulator/turtlebot_gazebo/worlds/my_world.world" &
sleep 10

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${path_catkin_ws}/src/map/map.yaml" &

sleep 10

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch"&
sleep 10

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers"&
sleep 5
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun pick_objects simple_navigation_goals"
