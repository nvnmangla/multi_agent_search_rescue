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
 * @file Swat.hpp
 * @author Naveen Mangla (namangla@umd.edu)
 * @author Mahima Arora (marora1@umd.edu)
 * @author Naveen Mangla (agarg125@umd.edu)
 * @brief Swat Class Definition
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_SWAT_HPP_
#define INCLUDE_SWAT_HPP_

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/package.h>
#include <tf/transform_listener.h>

#include <map>
#include <memory>
#include <robot.hpp>
#include <string>
#include <utility>
#include <vector>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>
    MoveBaseClient;

class Swat {
 public:
  /**
   * @brief Construct a new Swat object
   *
   * @param nh
   * @param robots
   */
  explicit Swat(ros::NodeHandle nh, std::vector<Robot *> robots);
  ~Swat();
  bool moving;  // Status

  /**
   * @brief Get the goal object
   *
   * @param goal_
   * @return move_base_msgs::MoveBaseGoal
   */
  move_base_msgs::MoveBaseGoal get_goal(std::pair<float, float> goal_);

  /**
   * @brief Set the client object
   *
   * @param robot
   * @param client
   */
  void set_client(Robot *robot);
  /**
   * @brief Move to the goal position
   *
   * @param robot
   */
  void move_to_goal(Robot *robot);
  /**
   * @brief Wait for results
   *
   * @param client
   */
  void wait(std::unique_ptr<MoveBaseClient> client);
  /**
   * @brief Detect threats
   *
   * @param robot Robot
   * @return true
   * @return false
   */
  bool detect_enemy(Robot *robot);

  /**
   * @brief Move all the swat robots
   *
   * @param robots
   */
  void move(std::vector<Robot *> robots);
  /**
   * @brief Terminate the enemy
   *
   * @param robot
   */
  void kill_enemy(Robot *robot);

 private:
  std::map<std::string, std::unique_ptr<MoveBaseClient>> clients;

  std::string robot_name;          // Name of robot
  ros::NodeHandle nh_;             // Node handle
  tf::StampedTransform transform;  // transform msg
  tf::TransformListener listner_;  // listner to transform
  ros::Publisher terminator_;      // publisher for terminate
};

std::pair<float, float> make_pair(float a, float b);

#endif  // INCLUDE_SWAT_HPP_
