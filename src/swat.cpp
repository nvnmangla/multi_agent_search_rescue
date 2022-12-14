#include <swat.hpp>
std::pair<float,float> make_pair(float a,float b){
        return std::pair<float,float>(a,b);
}

void Swat::move_to_goal(Robot &robot,std::unique_ptr<MoveBaseClient>&client){
    
    // ROS_INFO_STREAM("Moving to goal" + this->robot_name);

    
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

bool Swat::reach_goal(Robot &robot){


        try{
        this->listner_.lookupTransform("map", robot.name+"_tf/odom",  
                                ros::Time(0), transform);

        auto x = transform.getOrigin().getX();
        auto y = transform.getOrigin().getY();

        auto dis = pow((x - robot.goal_.first),2) + pow((y - robot.goal_.second),2);
        // ROS_INFO_STREAM("Distance from Goal"<<dis);
        if (sqrt(dis) < 5){
            robot.rescued = true;
            return true;
        }
        else return false;
        
        }
        catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
        ros::Duration(1.0).sleep();
        return false;
        }
    

}

void Swat::move(std::vector<Robot*>robots){
        for(int i=0;i<robots.size();i++){
            auto robot = *robots[i];
            move_to_goal(robot,clients[robot.name]);
            if (reach_goal(robot)){
                clients[robot.name]->cancelGoal();
                ROS_INFO_STREAM("Person: Thanks " + robot.name + " for saving me");
            }

    }
}

Swat::Swat(ros::NodeHandle nh,std::vector<Robot*>robots){

            nh_ = nh;
            // robot_name = robot.name;
            
            for(int i=0;i<robots.size();i++){
                    auto robot = *robots[i];
                
                    ROS_INFO_STREAM("Robot Initialized with name "+robot.name);
                    this->set_client(robot,clients[robot.name]);
                    this->moving = false;
            }
                
        }

Swat::~Swat(){};