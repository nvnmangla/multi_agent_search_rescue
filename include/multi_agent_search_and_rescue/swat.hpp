#include <ros/package.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>

class Swat{
    public:
        Swat(std::string name){
            robot_name = name;
        }
        void move_to_goal(std::pair<float,float> goal){
            
        }
    
    private:
        std::string robot_name;

};