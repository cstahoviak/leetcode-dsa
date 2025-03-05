/**
 * @file test_stacks_and_queues.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for algorithms related to the stack and queue data
 * structures.
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
  const std::string path1{"/home/"};
  EXPECT_EQ(simplify_path(path1), "/home");

  const std::string path2{"/home//foo/"};
  EXPECT_EQ(simplify_path(path2), "/home/foo");

  const std::string path3{"/home/user/Documents/../Pictures"};
  EXPECT_EQ(simplify_path(path3), "/home/user/Pictures");

  const std::string path4{"/../"};
  EXPECT_EQ(simplify_path(path4), "/");

  const std::string path5{"/.../a/../b/c/../d/./"};
  EXPECT_EQ(simplify_path(path5), "/.../b/d");
}

TEST(TestStacksAndQueues, TestMakeStringGreat) {
  EXPECT_EQ(make_great("leEeetcode"), "leetcode");
  EXPECT_EQ(make_great("abBAcC"), "");
  EXPECT_EQ(make_great("s"), "s");
}

TEST(TestStacksAndQueues, TestMovingAverage) {
  MovingAverage moving_avg(3);
  const std::vector<int> nums {1, 10, 3, 5};
  const std::vector<float> expected {1, 5.5, 4.66666651, 6.0};

  std::vector<float> avgs;
  for ( const int& num : nums ) {
    avgs.push_back(moving_avg.next(num));
  }
  EXPECT_EQ(avgs, expected);
}

TEST(TestStacksAndQueues, TestNextGreaterElement) {
  // Define the test data
  const std::pair<std::vector<int>, std::vector<int>> data1 = {
    {4, 1, 2}, {1, 3, 4, 2}
  };
  const std::pair<std::vector<int>, std::vector<int>> data2 = {
    {2, 4}, {1, 2, 3, 4}
  };
  const std::pair<std::vector<int>, std::vector<int>> data3 = {
    {3, 5, 1, 0, 7}, {2, 3, 5, 1, 0, 7, 6}
  };
  const std::pair<std::vector<int>, std::vector<int>> data4 = {
    {137, 59, 92, 122, 52, 131, 79, 236, 94},
    {137, 59, 92, 122, 52, 131, 79, 236, 94}
  };


  // Define the expeced results
  const std::vector<int> expected1 = {-1, 3, -1};
  const std::vector<int> expected2 = {3, -1};
  const std::vector<int> expected3 = {5, 7, 7, 7, -1};
  const std::vector<int> expected4 = {236, 92, 122, 131, 131, 236, 236, -1, -1};

  EXPECT_EQ(next_greater_element(data1.first, data1.second), expected1);
  EXPECT_EQ(next_greater_element(data2.first, data2.second), expected2);
  EXPECT_EQ(next_greater_element(data3.first, data3.second), expected3);
  EXPECT_EQ(next_greater_element(data4.first, data4.second), expected4);
}

TEST(TestStacksAndQueues, TestOnlineStockSpan) {
  // Define the test data
  const std::vector<int> data = { 100, 80, 60, 70, 60, 75, 85 };
  const std::vector<int> expected = { 1, 1, 1, 2, 1, 4, 6 };

  StockPanner<int> spanner;
  std::vector<int> result;
  for ( const int& val : data ) {
    result.push_back(spanner.next(val));
  }
  EXPECT_EQ(result, expected);

}