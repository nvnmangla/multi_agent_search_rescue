#include <swat.hpp>

std::pair<float,float> make_pair(float a,float b){
        return std::pair<float,float>(a,b);
}

void Swat::move_to_goal(std::pair<float,float>goal){
    
    while(!this->get_client()->waitForServer(ros::Duration(5.0))){
        
       ROS_INFO_STREAM("Waiting for the move_base action for " + this->robot_name +  "server to come up");
    }
    this->get_client()->sendGoal(this->get_goal(goal));
    ROS_INFO_STREAM("Moving to goal" + this->robot_name);
    this->moving = true;

}

std::unique_ptr<MoveBaseClient> Swat::get_client(){
    auto robot_client = std::make_unique<MoveBaseClient>(this->robot_name + "/move_base",true);
    return robot_client;

}

move_base_msgs::MoveBaseGoal Swat::get_goal(std::pair<float,float>&goal_){

    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = goal_.first;
    goal.target_pose.pose.position.y = goal_.second;
    goal.target_pose.pose.orientation.w = 1.0;
    return goal;
        
}

Swat::Swat(ros::NodeHandle nh,std::string name){
            nh_ = nh;
            robot_name = name;
            ROS_INFO_STREAM("Robot Initialized with name "+robot_name);
            this->moving = false;

        }

Swat::~Swat(){};