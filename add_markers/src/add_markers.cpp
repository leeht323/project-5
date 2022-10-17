  #include <ros/ros.h>
  #include <visualization_msgs/Marker.h>
  // #include <nav_msgs/Odometry.h>
  #include <move_base_msgs/MoveBaseActionResult.h>

  visualization_msgs::Marker marker;

  void listenMoveBaseResult(const move_base_msgs::MoveBaseActionResult msg){
    ROS_INFO("received action result");
    if(msg.status.status == 3){ //check reached goal(state == 3)
       if(marker.action == visualization_msgs::Marker::ADD){ //menas first seq is arrival at first goal
            ROS_INFO("Arrived at pick-up zone");
            ros::Duration(5).sleep(); // 5 seconds wait
            marker.action = visualization_msgs::Marker::DELETE;
            ROS_INFO("Picked up object (disappear object)");
            
        }
        else if(marker.action == visualization_msgs::Marker::DELETE){ //seq 2 = arrived at return goal
            ROS_INFO("Arrived at drop-off zone");
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = -0.67;
            marker.pose.position.y = -0.56;
            ROS_INFO("Dropped off object (appear object)");
        }
        else{
            ROS_INFO("ERROR, SOMETHING WRONG, Should check the seq of result topic");
        }
    }
}

  int main( int argc, char** argv )
   {
    ros::init(argc, argv, "basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Subscriber sub1 = n.subscribe("/move_base/result", 1, listenMoveBaseResult);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    marker.type = visualization_msgs::Marker::CUBE;   
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
      // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "object_shapes";
    marker.id = 0;
    marker.header.frame_id = "/map";
    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.2;
    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
    // the position when thread start
    marker.pose.position.x = 1.2;
    marker.pose.position.y = 0.8;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    while (ros::ok())
    {      
      marker.header.stamp = ros::Time::now(); 
      marker_pub.publish(marker);
      ros::spinOnce();
      r.sleep();
    }
 }
