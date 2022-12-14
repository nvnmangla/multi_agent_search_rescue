#ifndef SWAT_HPP_
#define SWAT_HPP_

#include <ros/package.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include<robot.hpp>
#include <map>
#include <tf/transform_listener.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;



class Swat{
    public:
        explicit Swat(ros::NodeHandle nh,std::vector<Robot*>robots);
        ~Swat();
        bool moving;

        move_base_msgs::MoveBaseGoal get_goal(std::pair<float,float>&goal_);
        void set_client(Robot &robot,std::unique_ptr<MoveBaseClient>&client);
        // std::unique_ptr<MoveBaseClient> get_client();
        void move_to_goal(Robot &robot,std::unique_ptr<MoveBaseClient>&client);
        void wait(std::unique_ptr<MoveBaseClient>&client);
        // std::pair<float,float> make_pair(float a, float b);
        bool reach_goal(Robot &robot);

    
    private:
        std::map<std::string,std::unique_ptr<MoveBaseClient>>clients;
        // std::unique_ptr<MoveBaseClient>client1;
        std::string robot_name;
        ros::NodeHandle nh_;
        tf::TransformListener listner_;


};

std::pair<float,float>make_pair(float a, float b);

#endif