#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>


int main(int argc, char** argv) {
    ros::init(argc, argv, "square_turtle");
    ros::NodeHandle n;

    ros::Publisher twist_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    ros::Rate loop_rate(1);

    double side_length;
    int side_time;

    n.getParam("side_length", side_length);
    n.getParam("side_time", side_time);

    double side_speed = side_length / side_time;
    geometry_msgs::Twist twist;

    while (ros::ok()) {
        twist.linear.x = side_speed;
        twist.angular.z = 0.0;
        for (int i = 0; i < side_time; i++){
            twist_pub.publish(twist);
            loop_rate.sleep();
        }

        // once reaching edge, reset linear speed to 0
        twist.linear.x = 0.0;
        twist.angular.z = -M_PI / 2;
        for (int i = 0; i < 1; i++) { // trivial but to demonstrate 1 loop (1 second)
            twist_pub.publish(twist);
            loop_rate.sleep();
        }
    }

    ros::spinOnce();
    return 0;
}