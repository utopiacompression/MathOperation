#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "straightline_turtle");
  ros::NodeHandle n;

  // create a publisher to relay the twist msg
  ros::Publisher twist_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  ros::Rate loop_rate(1); // 10 iterations per second
  // initialize a Twist message

  int time;
  n.getParam("time", time);
  geometry_msgs::Twist twist;

  // construct the Twist message
  twist.linear.x = 1.0;
  twist.angular.z = 0,0;

  for(int i = 0; i < time; i++) { //move "time" iterations / 1 hz = "time" seconds
    twist_pub.publish(twist);
    loop_rate.sleep();
  }

  ros::spinOnce();

  return 0;
  
}