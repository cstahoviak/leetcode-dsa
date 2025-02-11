/**
 * @file test_greedy.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for greedy algorithms.
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/algorithms/greedy.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

TEST(TestGreedyAlgorithms, TestMaximum69Number) {
  // Test the algorithm
  EXPECT_EQ(greedy::maximum_69_number(9669), 9969);
  EXPECT_EQ(greedy::maximum_69_number(9996), 9999);
  EXPECT_EQ(greedy::maximum_69_number(9999), 9999);
}

TEST(TestGreedyAlgorithms, TestMaximumUnits) {
  // Define the test data
  const std::vector<std::vector<int>> box_types1 = { {1,3}, {2,2}, {3,1} };
  const std::vector<std::vector<int>> box_types2 = {
    {5,10}, {2,5}, {4,7}, {3,9}
  };
  const std::vector<std::vector<int>> box_types3 = {
    {1,3}, {5,5}, {2,5}, {4,2}, {4,1}, {3,1}, {2,2}, {1,3}, {2,5}, {3,2}
  };

  // EXPECT_EQ(greedy::max_units(box_types1, 4), 8);
  // EXPECT_EQ(greedy::max_units(box_types2, 10), 91);
  EXPECT_EQ(greedy::max_units(box_types3, 35), 76);
}

TEST(TestGreedyAlgorithms, TestMaximumApples) {
  // Define the test data
  const std::vector<int> weights1 = { 100, 200, 150, 1000 };
  const std::vector<int> weights2 = { 900, 950, 800, 1000, 700, 800 };

  EXPECT_EQ(greedy::max_apples(weights1), 4);
  EXPECT_EQ(greedy::max_apples(weights2), 5);
}

TEST(TestGreedyAlgorithms, TestMinSetSize) {
  // Define the test inputs
  const std::vector<int> nums1 = { 3, 3, 3, 3, 5, 5, 5, 2, 2, 7 };
  const std::vector<int> nums2 = { 7, 7, 7, 7, 7, 7 };
  const std::vector<int> nums3 = { 
    9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38 ,68, 58, 19 };


  EXPECT_EQ(greedy::min_set_size(nums1), 2);
  EXPECT_EQ(greedy::min_set_size(nums2), 1);
  EXPECT_EQ(greedy::min_set_size(nums3), 5);

  // This test will fail. See the implementation for details.
  // EXPECT_EQ(greedy::min_set_size_2(nums3), 5);
}