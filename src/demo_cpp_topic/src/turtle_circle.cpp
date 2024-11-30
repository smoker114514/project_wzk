#include"rclcpp/rclcpp.hpp"
#include"geometry_msgs/msg/twist.hpp"
#include<chrono>
using namespace std::chrono_literals;

class turtlecircle: public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
public:
    turtlecircle(const std::string& node_name):Node(node_name)
    {
        publisher=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
        timer=this->create_wall_timer(1000ms,std::bind(&turtlecircle::timer_callback,this));
    }
    void timer_callback()
    {
        auto msg=geometry_msgs::msg::Twist();
        msg.linear.x=1.0;
        msg.angular.z=0.5;
        publisher->publish(msg);
    }
};
int main(int argc,char* argv[]){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<turtlecircle>("turtle_circle");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}