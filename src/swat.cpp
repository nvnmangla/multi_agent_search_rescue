/************************************************************************************
 * Apache Liscence 2.0
 * Copyright (c) 2021, Mahima Arora
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ************************************************************************************/

/**
 * @file swat.cpp
 * @author Naveen Mangla (namangla@umd.edu)
 * @author Mahima Arora (marora1@umd.edu)
 * @author Naveen Mangla (agarg125@umd.edu)
 * @brief Swat class Functions
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <swat.hpp>

std::pair<float, float> make_pair(float a, float b) {
  return std::pair<float, float>(a, b);
}

void Swat::move_to_goal(Robot *robot) {
  if (!(clients[robot->name]->getState() ==
        actionlib::SimpleClientGoalState::SUCCEEDED)) {
    clients[robot->name]->sendGoal(this->get_goal(robot->goal_));
    this->moving = true;
  } else {
    clients[robot->name]->cancelGoal();
  }
}

void Swat::set_client(Robot *robot) {
  clients[robot->name] =
      std::make_unique<MoveBaseClient>(robot->name + "/move_base", true);
  while (!clients[robot->name]->waitForServer(ros::Duration(5.0))) {
    ROS_INFO_STREAM("Waiting for the action server " + robot->name);
  }
}

void Swat::wait(std::unique_ptr<MoveBaseClient> client) {
  client->waitForResult();
}

move_base_msgs::MoveBaseGoal Swat::get_goal(std::pair<float, float> goal_) {
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = goal_.first;
  goal.target_pose.pose.position.y = goal_.second;
  goal.target_pose.pose.orientation.w = 1.0;
  return goal;
}

bool Swat::detect_enemy(Robot *robot) {
  try {
    this->listner_.lookupTransform(robot->name + "_tf/base_footprint",
                                   robot->target_name + "_tf/base_footprint",
                                   ros::Time(0), transform);
    auto x = transform.getOrigin().getX();
    auto y = transform.getOrigin().getY();
    auto dis = pow((x), 2) + pow((y), 2);
    if (sqrt(dis) < 2) {
      ROS_WARN("Enemy Inside !!");
    } else {
      return false;
    }
  } catch (tf::TransformException ex) {
    ROS_ERROR("%s", ex.what());
    ros::Duration(1.0).sleep();
    return false;
  }
}

void Swat::kill_enemy(Robot *robot) {
  if (detect_enemy(robot)) {
    terminator_ = nh_.advertise<geometry_msgs::Twist>(
        robot->target_name + "/cmd_vel", 10);
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

void Swat::move(std::vector<Robot *> robots) {
  for (int i = 0; i < robots.size(); i++) {
    move_to_goal(robots[i]);
    kill_enemy(robots[i]);
  }
}

Swat::Swat(ros::NodeHandle nh, std::vector<Robot *> robots) {
  nh_ = nh;
  for (int i = 0; i < robots.size(); i++) {
    ROS_INFO_STREAM("Robot Initialized with name " + robots[i]->name);
    this->set_client(robots[i]);
    this->moving = false;
  }
}

Swat::~Swat() {}
