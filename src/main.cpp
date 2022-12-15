#include<swat.hpp>
#include <threats.hpp>

int main(int argc ,char** argv){
    auto goal_1= make_pair(9,9);
    auto goal_2 = make_pair(-5,9);
    auto goal_3 = make_pair(2,5);
    auto goal_4 = make_pair(-9,6);
    auto goal_5 = make_pair(-9,0);

    Robot robot1("robot1","robot15",goal_1);
    Robot robot2("robot2","robot17",goal_2);
    Robot robot3("robot3","robot11",goal_3);
    Robot robot4("robot4","robot16",goal_4);
    Robot robot5("robot5","robot20",goal_5);
    Robot robot6("robot20");


    std::vector<Robot*>swat = {
        &robot1, //&robot2, &robot3, &robot4, &robot5
    };

    std::vector<Robot*>threats = {
        &robot6, //&robot2, &robot3, &robot4, &robot5
    };

    ros::init(argc, argv, "chopchop");
    ros::NodeHandle nh;

    Threats killers(nh,threats);
    Swat savers(nh,swat);

    while(ros::ok){
        savers.move(swat);
        killers.move(threats);
        
    }
    ros::shutdown();

    return 0;
}