# Final Project - Multi-Agent Search Rescue
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
![CICD Workflow status](https://github.com/mahimaarora2208/multi_agent_search_rescue/actions/workflows/build_and_coveralls.yml/badge.svg)
[![codecov](https://codecov.io/gh/mahimaarora2208/my-ros2-codecov-exp/branch/main/graph/badge.svg?token=AEULJJEMWV)](https://codecov.io/gh/mahimaarora2208/multi_agent_search_rescue)

## Project Description 
## Overview
This package simulates a Multi-agent system for search and rescue missions where we use turtlebot3 package in ROS Noetic. Our multi-agent system consists of 2- robots that are each specialized for a certain task. 5 turtlebots will be simulated as threats and another 5 turtlebots will be simulating the behavior of security forces (SWAT). The objective of the SWAT bots is to neutralize the threats and then go on to rescue the hostages. The SWAT knows the location of the hostages.

This software is a stepping stone in developing and studying the interaction between security forces and the adversaries. The objective is run all the swat bot simultaneously without bumping into each other.

## Background
The project will help us to gain insight as to how ROS Noetic, Gazebo and RViz works. The goal is to have understanding as to how services and nodes work. Gazebo and Rviz was another tool which we plan to learn through this project

## Deliverables
* Project: Muti-Agent Search and Rescue
* Overview of prosposed work, including risks, mitigation, timeline
* UML and activity diagrams
* Developer-level documentation
## Final Project Team: Group 1

 - Naveen Mangla (https://github.com/nvnmangla)
 - Mahima Arora  (https://github.com/mahimaarora2208)
 - Abhinav Garg  (https://github.com/15abhinavgarg)

## Development Team

Sprint | #1 | #2 | #3 |
--- | --- | --- | ---
Naveen Mangla | Design Keeper | Navigator | Driver
Mahima Arora | Navigator | Driver | Navigator
Abhinav Garg | Driver | Design Keeper | Design Keeper  

## Dependencies/ Assumptions

- OS : Ubuntu 20.04 
- ROS Distro : ROS Noetic
- Package build type : ```ament_cmake ```
- Package dependencies : ```rclcpp```, ```std_msgs``` 
- ROS Noetic Installation : [link](http://wiki.ros.org/noetic)

## External Dependencies

- [ROS Noeitic](http://wiki.ros.org/noetic)
- [Gazebo](http://gazebosim.org/)
- [Move Base](http://wiki.ros.org/move_base)
- [RViz](http://wiki.ros.org/rviz)


## Github CI and Codecov

Badges for Github CI and codecov are located at the top of the readme file. 
Additional information on building the software to test for coverage is shown below. 

## License
We are going with a Apache 2.0 License.

## AIP Development

This project will be completed using AIP process with the involvement of 3 programmers using Pair-programming in turns. One of the programmer would be driver while other 2 would be navigator and design keeper. The detailed Product Backlog, Iteration Backlogs and Work Log are mentioned in the link given below :

[Agile Iterative Process](https://docs.google.com/spreadsheets/d/1mDrRoUfZzBNDNiOhypIE3cQk9wSGpyxWhO2YZYkp0Ic/edit?usp=sharing)

## Important Links
   * [Phase 1 Proposal](https://drive.google.com/file/d/1Q7Ae7BqAT_y9z2TzFeA78kWwCRC0aNpY/view?usp=share_link)
   * [Phase 1 Video](https://drive.google.com/file/d/1j9FvWYJ_o5ee0BTNtfcTjndG6ISZVPU-/view)
   * [UML Class Diagram Phase 1](https://drive.google.com/file/d/1heAoCuE7eX8_rLSVcIel38kI9LPRAprV/view?usp=share_link)
   * [Activity Diagram Phase 1](https://drive.google.com/file/d/1A6i3RmnGnbHXjkOn1xPDj8RQZXLSRa0C/view?usp=share_link)
   * [UML Class Diagram Phase 2](#generating-documentation)
   * [Activity Diagram Phase 2](https://drive.google.com/file/d/1A6i3RmnGnbHXjkOn1xPDj8RQZXLSRa0C/view?usp=share_link))
   * [Quad Chart](https://drive.google.com/file/d/1Q7Ae7BqAT_y9z2TzFeA78kWwCRC0aNpY/view?usp=share_link)
   * [Video Demonstration](#uml-class-diagram)
   * [](#known-issues)

## Sprint Planning Notes
The below link contains combined notes of sprint 1,2 and 3.
[Link](https://docs.google.com/document/d/11oySgE_zwOvXpFovoRmgSecJl7ENY24lKy-PxDtwdi0/edit?usp=sharing)

## World
* We created a custom gazebo world which could simulate the requirements for our project

![image](https://github.com/mjoshi07/project_finder/blob/dev_phase2/data/gazebo_world.png)
* For the custom world, we also generated a binary occupancy grid, loaded in rviz

![image](https://github.com/mjoshi07/project_finder/blob/dev_phase2/data/rviz_map.png)


## Static Code analysis
* Cppcheck results can be found [here](https://github.com/mjoshi07/project_finder/blob/dev_phase2/results/cppcheck.txt)
* Cpplint results can be found [here](https://github.com/mjoshi07/project_finder/blob/dev_phase2/results/cpplint.txt)
## How to Run the ROS Package
### Build Instructions
```
cd <your_ROS2_ws>/src
git clone https://github.com/mahimaarora2208/multi_agent_hostage_rescue.git
cd ..   
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select multi_agent_hostage_rescue
source . install/setup.bash
source ~/<your ROS2 installation>/opt/ros/galactic/setup.bash
```

### ROS Run TESTS
Run the following commands to test your test cases:
```
colcon build --packages-select multi_agent_hostage_rescue
source install/setup.bash
colcon test --packages-select multi_agent_hostage_rescue
colcon test --event-handlers console_direct+ --packages-select multi_agent_hostage_rescue 
colcon test-result --test-result-base build/multi_agent_hostage_rescue
echo $?
```

## To Generate and Check code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## To Generate Doxygen Documentation
open your terminal in your repository
```
doxywizard
```
Follow steps in GUI after selecting path of your repository.