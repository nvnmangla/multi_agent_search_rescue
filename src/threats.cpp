#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char**argv){
size_t temp = 500; 
size_t cycle = 0;

ros::init(argc, argv, "publish_velocity");
ros::NodeHandle nh;

ros::Publisher pub11 = nh.advertise<geometry_msgs::Twist>("/robot11/cmd_vel", 1000);
ros::Publisher pub15 = nh.advertise<geometry_msgs::Twist>("/robot15/cmd_vel", 1000);
ros::Publisher pub16 = nh.advertise<geometry_msgs::Twist>("/robot16/cmd_vel", 1000);
ros::Publisher pub17 = nh.advertise<geometry_msgs::Twist>("/robot17/cmd_vel", 1000);
ros::Publisher pub20 = nh.advertise<geometry_msgs::Twist>("/robot20/cmd_vel", 1000);
int count = 0;
srand(time(0));

ros::Rate rate(2);
while(ros::ok()){
    geometry_msgs::Twist msg;

    if(cycle == 3){
        msg.linear.x = 0
        pub11.publish(msg);
        pub15.publish(msg);
        pub16.publish(msg);
        pub17.publish(msg);
        pub20.publish(msg);
        
        exit(EXIT_SUCCESS);
    }
    else{
        if (count_ < temp) // 500
        {
            msg.linear.x = 0;
            msg.angular.z = 0.1;
            publisher_->publish(message);
            RCLCPP_INFO_STREAM(this->get_logger(), "State = STOP");
            RCLCPP_INFO(
            this->get_logger(), "Count %f", double(count_));
            RCLCPP_INFO(
            this->get_logger(), "Cycle %f", double(cycle));
        }
      

        pub11.publish(msg);
        pub15.publish(msg);
        pub16.publish(msg);
        pub17.publish(msg);
        pub20.publish(msg);
            

        ROS_INFO_STREAM("Sending velocity command to threats:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

        rate.sleep();
        ROS_INFO_STREAM("COUNT: "<<count<<"  CYCLE: "<<cycle);
        count++;

        if(count == 50){
            count = 0;
            cycle++;
        }
    }
   
   
} 
}