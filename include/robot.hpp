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
 * @file robots.hpp
 * @author Naveen Mangla (namangla@umd.edu)
 * @author Mahima Arora (marora1@umd.edu)
 * @author Naveen Mangla (agarg125@umd.edu)
 * @brief Robot Class Definition
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/package.h>

#include <string>
#include <utility>

class Robot {
 public:
  /**
   * @brief Construct a new Robot object for Swat
   *
   * @param robot_name
   * @param threat_name
   * @param goal
   */
  explicit Robot(const std::string robot_name, const std::string threat_name,
                 std::pair<float, float> goal) {
    name = robot_name;          // Robot namespace
    goal_ = goal;               // Goal Location
    target_name = threat_name;  // Threat at Goal
    moving = true;              // Moving Status
    rescued = false;            // Hostage rescued or not
    terminated = false;         // Threat terminated
  }

  /**
   * @brief Construct a new Robot object for Threat
   *
   * @param robot_name
   */
  explicit Robot(const std::string robot_name) {
    name = robot_name;
    terminated = false;
  }

  std::string name;
  std::string target_name;
  std::pair<float, float> goal_;
  bool rescued;
  bool terminated;
  bool moving;
};

#endif  // INCLUDE_ROBOT_HPP_
