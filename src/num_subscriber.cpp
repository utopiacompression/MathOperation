#include "ros/ros.h"
#include "math_operation/mathop.h"


class Listener{
private:
  float result = 0.0;

public:
  void callback(const math_operation::mathop msg) {
      std::string op = msg.operation;
      ROS_INFO("Subscribed: %f %s %f", msg.num1, msg.operation.c_str(),msg.num2);
      if (op == "+") result = msg.num1 + msg.num2;
      if (op == "-") result = msg.num1 - msg.num2;
      if (op == "*") result = msg.num1 * msg.num2;
      if (op == "/") result = msg.num1 / msg.num2;
      ROS_INFO("The result is %f", result);
  }

  float getResult() const{
    return result;
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "num_sub");
  ros::NodeHandle n;

  Listener listener;
  ros::Subscriber sub = n.subscribe("/do_math", 1000, &Listener::callback, &listener);
  ROS_INFO("The result is %f", listener.getResult());

  ros::spin();

  return 0;
}