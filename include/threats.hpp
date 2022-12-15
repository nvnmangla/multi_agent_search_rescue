#ifndef THREATS_HPP_
#define THREATS_HPP_

#include <ros/package.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Twist.h>
#include<robot.hpp>
#include<map>
class Threats{
    public:
        explicit Threats(ros::NodeHandle &nh,std::vector<Robot*>&threats);
        bool terminated;
        void move(std::vector<Robot*>threats);
        ~Threats();

        
    private:

        ros::NodeHandle nh_;
        std::map<std::string,ros::Publisher>publishers;
};

#endif