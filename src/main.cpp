#include<swat.hpp>

int main(int argc ,char** argv){
    auto goal_1= make_pair(9,9);
    auto goal_2 = make_pair(-5,9);
    auto goal_3 = make_pair(2,5);
    auto goal_4 = make_pair(-9,6);
    auto goal_5 = make_pair(-9,0);

    Robot robot1("robot1",goal_1);
    Robot robot2("robot2",goal_2);
    Robot robot3("robot3",goal_3);
    Robot robot4("robot4",goal_4);
    Robot robot5("robot5",goal_5);

    std::vector<Robot*>robots = {
        &robot1, &robot2, &robot3, &robot4, &robot5
    };

    ros::init(argc, argv, "finder");
    ros::NodeHandle nh;
    Swat chopchop(nh,robots);
    return 0;
}