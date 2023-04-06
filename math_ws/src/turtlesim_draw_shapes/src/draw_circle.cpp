#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "circle_turtle");
    ros::NodeHandle n;

    ros::Publisher twist_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    ros::Rate loop_rate(10); // 10 loop per second

    double linear_speed, radius;
    // get params from yaml file
    n.getParam("linear_speed", linear_speed);
    n.getParam("radius", radius);

    // Create Twist msg for later publish
    geometry_msgs::Twist twist;

    while (ros::ok()){
        twist.linear.x = linear_speed;
        twist.angular.z = linear_speed / radius; //angular speed = linear_speed / radius
        twist_pub.publish(twist);

        loop_rate.sleep();
    }

    ros::spinOnce();

    return 0;

}