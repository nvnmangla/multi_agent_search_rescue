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
 * @file main.cpp
 * @author Naveen Mangla (namangla@umd.edu)
 * @author Mahima Arora (marora1@umd.edu)
 * @author Naveen Mangla (agarg125@umd.edu)
 * @brief Main function for finder node
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <swat.hpp>
#include <threats.hpp>

int main(int argc, char** argv) {
  // Creating Goals
  auto goal_1 = make_pair(9, 9);
  auto goal_2 = make_pair(-5, 9);
  auto goal_3 = make_pair(2, 5);
  auto goal_4 = make_pair(-9, 6);
  auto goal_5 = make_pair(-9, 0);

  // initializing robots
  Robot robot1("robot1", "robot15", goal_1);
  Robot robot2("robot2", "robot17", goal_2);
  Robot robot3("robot3", "robot11", goal_3);
  Robot robot4("robot4", "robot16", goal_4);
  Robot robot5("robot5", "robot20", goal_5);
  Robot robot6("robot15");
  Robot robot7("robot17");
  Robot robot8("robot11");
  Robot robot9("robot16");
  Robot robot10("robot20");

  // Making robot vectors
  std::vector<Robot*> swat = {&robot1, &robot2, &robot3, &robot4, &robot5};

  std::vector<Robot*> threats = {&robot6, &robot7, &robot8, &robot9, &robot10};

  // Initiated Node
  ros::init(argc, argv, "chopchop");
  ros::NodeHandle nh;

  Threats killers(nh, threats);
  Swat savers(nh, swat);

  while (ros::ok) {
    savers.move(swat);      // Running Swat
    killers.move(threats);  // Running Threats
  }
  ros::shutdown();

  return 0;
}
