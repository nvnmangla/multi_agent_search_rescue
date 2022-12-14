#include <swat.hpp>
std::pair<float,float> make_pair(float a,float b){
        return std::pair<float,float>(a,b);
}

void Swat::move_to_goal(Robot &robot,std::unique_ptr<MoveBaseClient>&client){
    
    ROS_INFO_STREAM("Moving to goal" + this->robot_name);
    client->sendGoal(this->get_goal(robot.goal_));
    this->moving = true;
}


void Swat::set_client(Robot &robot,std::unique_ptr<MoveBaseClient>&client){

    client = std::make_unique<MoveBaseClient>(robot.name + "/move_base",true);
    while (!client->waitForServer(ros::Duration(5.0))) {
        ROS_INFO_STREAM("Waiting for the action server "+ this->robot_name);
    }


}

void Swat::wait(std::unique_ptr<MoveBaseClient>&client){
    client->waitForResult();
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

Swat::Swat(ros::NodeHandle nh,std::vector<Robot*>robots){

            nh_ = nh;
            // robot_name = robot.name;
            for(int i=0;i<robots.size();i++){
                auto robot = *robots[i];
                // auto client = clients[robot.name];
                ROS_INFO_STREAM("Robot Initialized with name "+robot.name);
                this->set_client(robot,clients[robot.name]);
                this->moving = false;
                this->move_to_goal(robot,clients[robot.name]);
            }

        }

Swat::~Swat(){};