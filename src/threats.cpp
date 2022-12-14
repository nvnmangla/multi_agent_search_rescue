#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char**argv){
size_t temp = 50; 
size_t cycle = 0;
double speed = 0.2;
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

    if(cycle == 15){
        msg.linear.x = 0;
        pub11.publish(msg);
        pub15.publish(msg);
        pub16.publish(msg);
        pub17.publish(msg);
        pub20.publish(msg);
        
        exit(EXIT_SUCCESS);
    }
    else{
        if (count < temp) // 50
        {
            msg.linear.x = 0;
        }
        else if (count < 1.5*temp) // 75
        {
            msg.linear.x = speed;
        }

        else if (count < 1.65*temp) // 85
        {
            msg.linear.x = 0.0;
        }
        
        else if (count < 2.15*temp) // 105
        {
            msg.linear.x = -speed;     
        }

        else if (count < 2.25*temp) // 125
        {
            count = 35;
            cycle++;
        }
        
        pub11.publish(msg);
        pub15.publish(msg);
        pub16.publish(msg);
        pub17.publish(msg);
        pub20.publish(msg);
        ROS_INFO_STREAM("Sending velocity command to threats:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);       
        ROS_INFO_STREAM("COUNT: "<<count<<"  CYCLE: "<<cycle);
    
        rate.sleep();
        count++;
    
    }      
}   
} 
