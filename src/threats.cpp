#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char**argv){
size_t temp = 50; 
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
        msg.linear.x = 0;
        pub11.publish(msg);
        pub15.publish(msg);
        pub16.publish(msg);
        pub17.publish(msg);
        pub20.publish(msg);
        
        exit(EXIT_SUCCESS);
    }
    else{
        if (count < temp) // 500
        {
            msg.linear.x = 0;
        }
        else if (count < 1.5*temp) // 750
        {
            msg.linear.x = 0.1;
        }

        else if (count < 1.55*temp) // 775
        {
            msg.linear.x = 0.0;
       
        }
        
        else if (count< 2.05*temp) // 1025
        {
            msg.linear.x = -0.1;     
        }

        else if (count < 2.1*temp) // 1050
        {
            count = 450;
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
