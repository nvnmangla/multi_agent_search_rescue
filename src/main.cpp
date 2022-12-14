#include<swat.hpp>

int main(int argc ,char** argv){
    
    ros::init(argc, argv, "finder");
    ros::NodeHandle nh;
    Swat robot1(nh,"robot1");
    
    auto goal_ = make_pair(9,9);
    
    robot1.move_to_goal(goal_);
    while(robot1.moving){
        robot1.get_client()->waitForResult();
    }
    return 0;
}