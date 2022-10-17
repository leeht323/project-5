This project is a scenario where a robot moves a specific object to another location.
-------------
The execution of that project is as follows:

-Environment: Robot moving in an indoor environment through GAZEBO simulation
-Mapping: Create a map corresponding to the indoor environment through the gmapping algorithm
-Location Awareness: Localization using lidar sensor data based on a map generated through mapping, Algorithm: AMCL
-Business Scenario (Sequence)
 1. There is a cube-shaped object located in the upper right corner of the map. The robot reaches the location through autonomous driving
 2. When the robot stops, the object is loaded onto the robot. (The object disappears from the visualization tool)
 3. After a 5 second pause, the robot moves through autonomous driving to the drop-off location
 4. After arriving at the drop-ff position, drop the object off the robot (object appears on the visualization tool).
