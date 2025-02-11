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
  const std::vector<std::vector<int>>  box_types2 = 
    { {5,10}, {2,5}, {4,7}, {3,9} };

  EXPECT_EQ(greedy::max_units(box_types1, 4), 8);
  EXPECT_EQ(greedy::max_units(box_types2, 10), 91);
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
  const std::vector<int> vec1 = { 3, 3, 3, 3, 5, 5, 5, 2, 2, 7 };
  const std::vector<int> vec2 = { 7, 7, 7, 7, 7, 7 };

  EXPECT_EQ(greedy::min_set_size(vec1), 2);
  EXPECT_EQ(greedy::min_set_size(vec2), 1);  
}