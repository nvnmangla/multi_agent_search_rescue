#include <swat.hpp>
std::pair<float,float> make_pair(float a,float b){
        return std::pair<float,float>(a,b);
}

void Swat::move_to_goal(Robot &robot){

    if (!(clients[robot.name]->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)){
        clients[robot.name]->sendGoal(this->get_goal(robot.goal_));
        this->moving = true;
    }
    else{

        clients[robot.name]->cancelGoal();
    }
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

bool Swat::detect_enemy(Robot &robot){
        try{
        this->listner_.lookupTransform(robot.name+"_tf/base_footprint",robot.target_name+"_tf/base_footprint",  
                                ros::Time(0), transform);
        auto x = transform.getOrigin().getX();
        auto y = transform.getOrigin().getY();
        auto dis = pow((x),2) + pow((y),2);
        if (sqrt(dis) < 2){
            ROS_WARN("Enemy Inside !!");
        }
        else return false;
        }
        catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
        ros::Duration(1.0).sleep();
        return false;
        }
    

}


void Swat::kill_enemy(Robot &robot){

    if(detect_enemy(robot)){
        terminator_ = nh_.advertise<geometry_msgs::Twist>(robot.target_name + "/cmd_vel",10);
        geometry_msgs::Twist msg;
        msg.linear.x = 0;
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 0;

        ROS_WARN("Shooting enemy ");    
        terminator_.publish(msg);

    }

}

void Swat::move(std::vector<Robot*>robots){
        for(int i=0;i<robots.size();i++){
            move_to_goal(*robots[i]);
            kill_enemy(*robots[i]);
    }
}

Swat::Swat(ros::NodeHandle nh,std::vector<Robot*>robots){
            nh_ = nh;
            for(int i=0;i<robots.size();i++){
                    auto robot = *robots[i];
                    ROS_INFO_STREAM("Robot Initialized with name "+robot.name);
                    this->set_client(robot,clients[robot.name]);
                    this->moving = false;
            }
        }

Swat::~Swat(){};