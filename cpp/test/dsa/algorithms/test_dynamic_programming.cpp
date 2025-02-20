/**
 * @file test_dynamic_programming.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for dynamic programming algorithms.
 * @version 0.1
 * @date 2025-02-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include "dsa/algorithms/dynamic_programming.h"

 #include <gtest/gtest.h>

 using namespace dsa::algorithms;

 TEST(TestDynamicProgramming, TestClimbStairs) {
  // Validate the algorithm
  EXPECT_EQ(dp::climb_stairs(2), 2);
  EXPECT_EQ(dp::climb_stairs(3), 3);
 }

 TEST(TestDynamicProgramming, TestMinCostClimbingStairs) {
  // Define the test data
  const std::vector<int> cost1 = { 10, 15, 20 };
  const std::vector<int> cost2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };

  // Validate the algorithm
  EXPECT_EQ(dp::min_cost_climbing_stairs(cost1), 15);
  EXPECT_EQ(dp::min_cost_climbing_stairs(cost2), 6);
 }

 TEST(TestDynamicProgramming, TestCoinChange) {
  // Define the test data
  const std::pair<std::vector<int>, int> data1 = {{ 1, 2, 5 }, 11};
  const std::pair<std::vector<int>, int> data2 = {{ 2 }, 3};
  const std::pair<std::vector<int>, int> data3 = {{ 1 }, 0};

  // Validate the algorithm
  EXPECT_EQ(dp::coin_change(data1.first, data1.second), 3);
  EXPECT_EQ(dp::coin_change(data2.first, data2.second), -1);
  EXPECT_EQ(dp::coin_change(data3.first, data3.second), 0);
 }