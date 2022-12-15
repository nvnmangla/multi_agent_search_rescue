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
 * @file threats.cpp
 * @author Naveen Mangla (namangla@umd.edu)
 * @author Mahima Arora (marora1@umd.edu)
 * @author Naveen Mangla (agarg125@umd.edu)
 * @brief Threat class Functions
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <threats.hpp>

Threats::Threats(ros::NodeHandle *nh, std::vector<Robot *> robots) {
  nh_ = *nh;
  for (int i = 0; i < robots.size(); i++) {
    this->publishers[robots[i]->name] =
        nh_.advertise<geometry_msgs::Twist>(+"/cmd_vel", 10);
    robots[i]->terminated = false;
  }
  ROS_INFO_STREAM("Threats Initiated");
}

void Threats::move(std::vector<Robot *> robots) {
  geometry_msgs::Twist msg;
  size_t temp = 50;
  size_t cycle = 0;
  double speed = 0.2;
  int count = 0;

  if (cycle == 15) {
    msg.linear.x = 0;
    for (int i = 0; i < robots.size(); i++) {
      if (!robots[i]->terminated) {
        this->publishers[robots[i]->name].publish(msg);
        ROS_INFO_STREAM("Publishing on " + robots[i]->name);
      }
    }

    exit(EXIT_SUCCESS);
  } else {
    if (count < temp) {
      msg.linear.x = 0;
    } else if (count < 1.5 * temp) {  // 75
      msg.linear.x = speed;
    } else if (count < 1.65 * temp) {
      msg.linear.x = 0.0;
    } else if (count < 2.15 * temp) {  // 105
      msg.linear.x = -speed;
    } else if (count < 2.25 * temp) {  // 125
      count = 35;
      cycle++;
    }
    // For every bot
    for (int i = 0; i < robots.size(); i++) {
      if (!robots[i]->terminated) {
        this->publishers[robots[i]->name].publish(msg);
      }
    }
    count++;
  }
}

Threats::~Threats() {}
