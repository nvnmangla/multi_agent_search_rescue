# Final Project - Multi-Agent Search Rescue
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
![CICD Workflow status](https://github.com/mahimaarora2208/multi_agent_search_rescue/actions/workflows/build_and_coveralls.yml/badge.svg)
[![codecov](https://codecov.io/gh/mahimaarora2208/my-ros2-codecov-exp/branch/main/graph/badge.svg?token=AEULJJEMWV)](https://codecov.io/gh/mahimaarora2208/multi_agent_search_rescue)

## Overview
This project simulates a Multi-agent system for search and rescue missions where we use turtlebot3 package in ROS2 Galactic. Our multi-agent system consists of 2- robots that are each specialized for a certain task. 8 turtlebots will be simulated as threats, another 8 turtlebots will be specific to neutralizing these threats and 4 people will be simulated using Aruco markers. The remaining 4 turtlebots will be used to rescue these 4 Search.

## Final Project Team: Group 1

 - Naveen Mangla - Driver (https://github.com/nvnmangla)
 - Mahima Arora - Navigator (https://github.com/mahimaarora2208)
 - Abhinav Garg - Designer (https://github.com/15abhinavgarg)


### Dependencies/ Assumptions
- OS : Ubuntu 20.04 
- ROS2 Distro : ROS2 Galactic
- Package build type : ```ament_cmake ```
- Package dependencies : ```rclcpp```, ```std_msgs``` 
- ROS2 Galactic Installation : [link](https://docs.ros.org/en/galactic/Installation/Ubuntu-Install-Debians.html)


## How to Run the ROS Package
### Build Instructions
```
cd <your_ROS2_ws>/src
git clone https://github.com/mahimaarora2208/multi_agent_Search_rescue.git
cd ..   
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select multi_agent_Search_rescue
source . install/setup.bash
source ~/<your ROS2 installation>/opt/ros/galactic/setup.bash
```

## AIP Development

This project will be completed using AIP process with the involvement of 3 programmers using Pair-programming in turns. One of the programmer would be driver while other 2 would be navigator and design keeper. The detailed Product Backlog, Iteration Backlogs and Work Log are mentioned in the link given below :

[Agile Iterative Process](https://docs.google.com/spreadsheets/d/1q81OENQQRdlFShR4wcxflBOyHls5yuyU/edit?usp=sharing&ouid=106728747057946217321&rtpof=true&sd=true)  # TO-D0 Needs to be updated

## Important Links

[Phase 0 Proposal](https://drive.google.com/file/d/1Q7Ae7BqAT_y9z2TzFeA78kWwCRC0aNpY/view?usp=share_link)

[Phase 0 Video](https://drive.google.com/file/d/1j9FvWYJ_o5ee0BTNtfcTjndG6ISZVPU-/view)

[UML Class Diagram Phase 0](https://drive.google.com/file/d/1heAoCuE7eX8_rLSVcIel38kI9LPRAprV/view?usp=share_link)

[Activity Diagram Phase 0](https://drive.google.com/file/d/1A6i3RmnGnbHXjkOn1xPDj8RQZXLSRa0C/view?usp=share_link) 

[UML Class Diagram Phase 1](https://drive.google.com/file/d/1u1SfBBqCDe6bCdI-nSmj1gVIL7Obzjpz/view?usp=share_link)

[Quad Chart](https://drive.google.com/file/d/1Q7Ae7BqAT_y9z2TzFeA78kWwCRC0aNpY/view?usp=share_link)

## Sprint Planning Notes
The below link contains combined notes of sprint 1.
[Link](https://docs.google.com/document/d/1eXNISSYEkhZfuHLOKzZ1n7hsESNZ54MTIxZAkLqt3zA/edit?usp=sharing)

## Downloading Dependencies
The main dependency that needs to be downloaded is openCV 4.2 or above.


```
# Installing Dependencies
sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config

# Cloning Git repository
git clone https://github.com/opencv/opencv.git;mkdir -p build && cd build

# CMAKE
cmake ../opencv;make -j4

# Installing OpenCV 
sudo make install
```

### ROS2 Run TESTS
Run the following commands to test your test cases:
```
colcon build --packages-select multi_agent_Search_rescue
source install/setup.bash
colcon test --packages-select multi_agent_Search_rescue
colcon test --event-handlers console_direct+ --packages-select multi_agent_Search_rescue 
colcon test-result --test-result-base build/multi_agent_Search_rescue
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