
#include<threats.hpp>

Threats::Threats(ros::NodeHandle &nh,std::vector<Robot*>&robots){
    nh_ = nh;
    for(int i=0;i<robots.size();i++){
        this->publishers[robots[i]->name] = nh_.advertise<geometry_msgs::Twist>(+"/cmd_vel", 10);
        robots[i]->terminated = false;    
        }
    ROS_INFO_STREAM("Threats Initiated");
}

void Threats::move(std::vector<Robot*>robots){
    geometry_msgs::Twist msg;
    size_t temp = 50; 
    size_t cycle = 0;
    double speed = 0.2;
    int count = 0;

    if(cycle == 15){
        msg.linear.x = 0;
        for(int i=0;i<robots.size();i++){
            if (!robots[i]->terminated){
                this->publishers[robots[i]->name].publish(msg);
                ROS_INFO_STREAM("Publishing on "+robots[i]->name);
            }
        }
        
        exit(EXIT_SUCCESS);
    }
    else{
        if (count < temp) // 50
        {
            msg.linear.x = 0;
        }
        else if (count < 1.5*temp) // 75
        {
            msg.linear.x = speed;
        }

        else if (count < 1.65*temp) // 85
        {
            msg.linear.x = 0.0;
        }
        
        else if (count < 2.15*temp) // 105
        {
            msg.linear.x = -speed;     
        }

        else if (count < 2.25*temp) // 125
        {
            count = 35;
            cycle++;
        }
    
    for(int i=0;i<robots.size();i++){
            if (!robots[i]->terminated){
            this->publishers[robots[i]->name].publish(msg);
            }
        }
        count++; 
        }  
    }      

Threats::~Threats(){

}
