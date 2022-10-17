BRIEF DESCRIPTION
------------
This project is a scenario where a robot moves a specific object to another location.
The execution of that project is as follows:

-Environment: Robot moving in an indoor environment through GAZEBO simulation

-Mapping: Create a map corresponding to the indoor environment through the gmapping algorithm

-Location Awareness: Localization using lidar sensor data based on a map generated through mapping, Algorithm: AMCL

-Business Scenario (Sequence)
 1. There is a cube-shaped object located in the upper right corner of the map. The robot reaches the location through autonomous driving
 2. When the robot stops, the object is loaded onto the robot. (The object disappears from the visualization tool)
 3. After a 5 second pause, the robot moves through autonomous driving to the drop-off location
 4. After arriving at the drop-ff position, drop the object off the robot (object appears on the visualization tool).





EXPLAIN THE PACKAGES 
------------------------
##### First of all, there are few significant packages used in this project to make robot autonomous.
    -turtlebot_gazebo
    -Gmapping
    -turtlebot_teleop
    -turtlebot_rviz_launchers
    -turtlebot_gazebo
    
    
  Gmapping package is a mapping package which is used to map the environment using the laser range finder sensor and odometry.
The result of this is a 2D occupancy grid map. This will be useful for localization and navigation later.
     
  The turtlebot_gazebo package basically provides an environment to use the turtlebot robot in the gazebo simulator environment. By providing a robot and its surroundings in a virtual environment, autonomous driving can be attempted.
  Also, we are providing a launch file so that we can perform localization and navigation using AMCL algorithm, and mapping using gmapping algorithm.
  In this regard, I have created a shell script file to make it easy to run each task.
	- Mapping : test_slam.sh
	- Localization & Navigation : test_navigation.sh

  The turtlebot_rviz_launchers package provides a visualization tool to visualize various processing of turtlebots. Through this, you can check the autonomous driving movement of the robot, real-time sensing information, and pick-up objects.

  The turtlebot_teleop package is a program that publishes control commands as topics so that you can manually manipulate the turtlebot, and it is especially useful for robot mapping.



##### In addition to the above open source packages, additional packages are included. This is as follows.
	- add_markers
	- pick_objects

  The pick_objects package provides programmed nodes where the robot drives itself and moves sequentially to two destinations.
  The first destination means the pick-up zone where the object to be transported is located, and the second destination means the drop-off zone where the object will be transported.
(There is pick_objects.sh to easily run this alone.)

  The add_markers package handles the processing of creating or deleting virtual objects to be moved by the robot according to specific situations. To be a little more specific,
  When the robot arrives at the location of the object, the object disappears, and when the robot arrives at another destination, the object is created at that location. This is to depict a robot carrying an object.
  When an object disappears and is re-created, it works according to the scenario of pick_objects above.
(There is add_marker.sh to easily run this alone.)

  Finally, run the "home_service.sh" script to run the entire scenario where the robot moves, loads the object, and puts it back down at its final destination.
  You will experience the fantastic experience of having our robot move objects for you.
