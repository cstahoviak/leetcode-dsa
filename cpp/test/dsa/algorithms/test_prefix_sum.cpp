/**
 * @file test_prefix_sum.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for the Prefix Sum algorithms.
 * @version 0.1
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "dsa/algorithms/prefix_sum.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

/**
 * @brief Unit test for the prefix_sum::get_prefix_sum algorithm. In the class
 * material, this appears as "Running Sum of 1D Array" example.
 */
TEST(TestPrefixSum, TestPrefixSumAlgorithm) {
  // Example test #1
  std::vector<int> nums = { 1, 2, 3, 4 };
  std::vector<int> expected = { 1, 3, 6, 10 };
  auto result = prefix_sum::get_prefix_sum(nums);

  ASSERT_EQ(result.size(), nums.size());
  for ( size_t idx = 0; idx < nums.size(); idx++ ) {
    ASSERT_EQ(result.at(idx), expected.at(idx));
  }

    // Example test #2
  std::vector<int> nums2 = { 1, 1, 1, 1, 1 };
  std::vector<int> expected2 = { 1, 2, 3, 4, 5 };
  auto result2 = prefix_sum::get_prefix_sum(nums2);
  
  ASSERT_EQ(result2.size(), nums2.size());
  for ( size_t idx = 0; idx < nums2.size(); idx++ ) {
    ASSERT_EQ(result2.at(idx), expected2.at(idx));
  }
}

/**
 * @brief Given an integer array 'nums', an array 'queries' (where 
 * queries[i] = [x, y]), and an integer 'limit', return a boolean array that 
 * represents the answer to each query. A query is true if the sum of the 
 * subarray from x to y is less than limit, or false otherwise.
 */
TEST(TestPrefixSum, TestQuerySum) {
  std::vector<int> nums = { 1, 6, 3, 2, 7, 2 };
  std::vector<std::vector<int>> queries = { {0, 3}, {2, 5}, {2, 4} };
  int limit = 13;
  std::vector<bool> result = prefix_sum::query_sum(nums, queries, limit);
  std::vector<bool> expected = {true, false, true};
  EXPECT_EQ(result, expected);
}

/**
 * @brief Given an integer array 'nums', find the number of ways to split the
 * array into two parts so that the first section has a sum greater than or
 * equal to the sum of the second section. The second section should have at
 * least one number.
 */
TEST(TestPrefixSum, TestBisectNWays) {
  std::vector<int> nums = { 10, 4, -8, 7 };
  auto valid_idxs = prefix_sum::bisect_n_ways(nums);

  std::vector<std::tuple<idx_tuple, idx_tuple>> expected_idxs = {
    {{0, 0}, {1, 3}},
    {{0, 1}, {2, 3}},
  };

  int idx = 0;
  for ( auto& [lsplice, rsplice] : valid_idxs ) {
    EXPECT_EQ(lsplice, std::get<0>(expected_idxs[idx]));
    EXPECT_EQ(rsplice, std::get<1>(expected_idxs[idx]));
    idx++;
  }
}

TEST(TestPrefixSum, MinimumPositveStartValue) {
  // Example 1:
  std::vector<int> nums { -3, 2, -3, 4, 2 };
  int expected{5};

  // Example 2: The minimum start value should be 
  std::vector<int> nums2 { 1, 2 };
  int expected2{1};

  GTEST_SKIP();
}

TEST(TestPrefixSum, KRadiusSubarrayAverages) {
  // Example 1:
  std::vector<int> nums { 7,4,3,9,1,8,5,2,6 };
  int k{3};
  std::vector<int> expected = { -1,-1,-1,5,4,4,-1,-1,-1 };

  // Example 2: The sum of the subarray centered at 0 with radius 0 is: 100000.
  nums.clear(); nums.push_back(100000);
  k = 0;
  expected.clear(); expected.push_back(100000);

  // Example 3: avg[0] is -1 because there are less than k elements before and
  // after index 0.
  nums.clear(); nums.push_back(8);
  k = 100000;
  expected.clear(); expected.push_back(-1);

  GTEST_SKIP();
}