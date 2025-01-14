/**
 * @file test_stacks_and_queues.cpp
 * @author Carl Stahoviak
 * @brief Unit tesrts for the stacks and queue data structure algorithms.
 * @version 0.1
 * @date 2025-01-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/data_structures/stacks_and_queues.h"

#include <gtest/gtest.h>

using namespace dsa::data_structures::stacks_and_queues;

TEST(TestStacksAndQueues, TestSimplifyPath) {
  GTEST_SKIP();

  std::string path1{"/home/"};
  EXPECT_EQ(simplify_path(path1), "/home");

  std::string path2{"/home//foo/"};
  EXPECT_EQ(simplify_path(path2), "/home/foo");

  std::string path3{"/home/user/Documents/../Pictures"};
  EXPECT_EQ(simplify_path(path3), "/home/user/Pictures");

  std::string path4{"/../"};
  EXPECT_EQ(simplify_path(path4), "/");

  std::string path5{"/.../a/../b/c/../d/./"};
  EXPECT_EQ(simplify_path(path5), "/.../b/d");
}

TEST(TestStacksAndQueues, TestMovingAverage) {
  MovingAverage moving_avg(3);
  std::vector<int> nums {1, 10, 3, 5};
  std::vector<float> expected {1, 5.5, 4.66666651, 6.0};

  std::vector<float> avgs;
  for ( const int& num : nums ) {
    avgs.push_back(moving_avg.next(num));
  }
  EXPECT_EQ(avgs, expected);
}