#include"rclcpp/rclcpp.hpp"
#include"geometry_msgs/msg/twist.hpp"
#include<chrono>
#include"turtlesim/msg/pose.hpp"
#include<cmath>
using namespace std::chrono_literals;

class turtlecontrol: public rclcpp::Node
{
private:
    //rclcpp::TimerBase::SharedPtr timer;
    double traget_x{2.0};
    double traget_y{8.0};
    double k_{1.0};
    double max_speed_{4.0};
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
public:
    turtlecontrol(const std::string& node_name):Node(node_name)
    {
        subscriber=this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&turtlecontrol::on_pose_received,this,std::placeholders::_1));
        publisher=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
        //timer=this->create_wall_timer(1000ms,std::bind(&turtlecontrol::timer_callback,this));
    }
    void on_pose_received(const turtlesim::msg::Pose::SharedPtr pose)
    {
        auto current_x=pose->x;
        auto current_y=pose->y;
        RCLCPP_INFO(get_logger(),"当前:x=%f,y=%f",current_x,current_y);
        auto distance=std::sqrt(pow(traget_x-current_x,2)+pow(traget_y-current_y,2));
        auto msg=geometry_msgs::msg::Twist();
        auto angle=std::atan2(traget_y-current_y,traget_x-current_x)-pose->theta;
        if(distance>0.1){
            if(fabs(angle)>0.2){
                msg.angular.z=fabs(angle);
            }
            else{
                msg.linear.x=k_*distance;
            }
        }
        if(msg.linear.x>max_speed_){
            msg.linear.x=max_speed_;
        }
        publisher->publish(msg);
    }
};
int main(int argc,char* argv[]){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<turtlecontrol>("turtle_control");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}