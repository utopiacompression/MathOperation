#include "ros/ros.h"
#include "math_operation/mathop.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "num_pub");
    ros::NodeHandle n;

    ros::Publisher num1_pub = n.advertise<math_operation::mathop>("/do_math", 1000);
    ros::Rate loop_rate(10);

    float num1, num2;
    std::string op;
    n.getParam("num1", num1);
    n.getParam("num2", num2);
    n.getParam("op", op);

    // Create the message
    math_operation::mathop msg;
    msg.num1 = num1;
    msg.num2 = num2;
    msg.operation = op;

    while (ros::ok()){
        math_operation::mathop msg;
        msg.num1 = num1;
        msg.num2 = num2;
        msg.operation = op;

        // %s expects a null-terminated string. 
        // to convert a std::string to a C-style null-terminated string, use c_str()
        ROS_INFO("Received from input/yaml file: %f %s %f", msg.num1, msg.operation.c_str(),msg.num2);

        num1_pub.publish(msg); 

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}