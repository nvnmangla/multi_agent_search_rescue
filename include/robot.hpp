#ifndef ROBOT_HPP
#define ROBOT_HPP


#include <ros/package.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>

class Robot{
    
    public:
        explicit Robot(const std::string robot_name,const std::string threat_name,std::pair<float,float>goal){
            name = robot_name;

            goal_ = goal;
            target_name = threat_name;
            moving =true;
            rescued = false;
            terminated = false;
        }
        
        std::string name;
        std::string target_name;
        std::pair<float,float>goal_;
        bool rescued;
        bool terminated;
        bool moving;

};







#endif ROBOT_HPP