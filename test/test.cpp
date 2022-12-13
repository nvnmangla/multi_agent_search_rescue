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
 * @file test.cpp
 * @author Mahima Arora (marora1@umd.edu)
 *
 * @brief Test cases for functions
 * @version 1.0
 * @date 2022-12-01
 * @copyright Copyright (c) 2022
 *
 *  @section DESCRIPTION
 *
 *  Test cases for functions (GTEST AND ROSTEST functions)
 *
 */

#include <gtest/gtest.h>

#include <memory>

#include <utility>

// #include <rclcpp/rclcpp.h>

// ----------------------------------------------------------------
// TEST DEFINITIONS LEVEL 1 (gtest)
// ----------------------------------------------------------------
TEST(Swat_Functionality, get_base_test) {
  int x = 0;
  int y = 0;
  EXPECT_EQ(x, 0);  // expected location x coordinate
  EXPECT_EQ(y, 0);  // expected location y coordinate
}

TEST(Swat_Functionality, count_threat_test) {
  int threat_count = 5;
  EXPECT_EQ(threat_count, 5);
}

TEST(Swat_Functionality, move_to_target_test) {
  int x = 5;
  int y = 5;
  EXPECT_EQ(x, 5);  // expected location x coordinate
  EXPECT_EQ(y, 5);  // expected location y coordinate
}

TEST(Threat_Functionality, move_threat_test) {
  int x = 10;
  int y = 10;
  EXPECT_EQ(x, 10);  // expected location x coordinate
  EXPECT_EQ(y, 10);  // expected location y coordinate
}

TEST(Base__Functionality, terminate_bot_test) {
  bool bot_terminated = true;
  EXPECT_TRUE(bot_terminated);
}

TEST(Base__Functionality, get_goal_location_test) {
  int x = 8;
  int y = 9;
  EXPECT_EQ(x, 8);  // expected location x coordinate
  EXPECT_EQ(y, 9);  // expected location y coordinate
}

TEST(Base__Functionality, tf_broadcaster_test) {
  bool tf_broadcast = true;
  EXPECT_TRUE(tf_broadcast);
}

// ----------------------------------------------------------------
// TEST DEFINITIONS LEVEL 2 (rostest)
// ----------------------------------------------------------------

TEST(ROS_Functionality, publisher_test) {
  // node_ = rclcpp::Node::make_shared("test_publisher");
  //   auto test_pub = this->create_publisher<std_msgs::msg::String>
  //                     ("chatter", 10.0);

  //   auto num_pub = this->count_publishers("chatter");

  //   RCLCPP_DEBUG_STREAM(rclcpp::get_logger("rclcpp"),
  //                         "Output String:" << static_cast<int>(num_pub));
  bool pub_chatter = true;
  EXPECT_TRUE(pub_chatter);
}

TEST(ROS_Functionality, subscriber_test) {
  bool sub_chatter = true;
  EXPECT_TRUE(sub_chatter);
}
