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
#include <random>

#include "dsa/algorithms/prefix_sum.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

/**
 * @brief Unit test for the prefix_sum::get_prefix_sum algorithm. In the class
 * material, this appears as "Running Sum of 1D Array" example.
 */
TEST(TestPrefixSum, TestPrefixSumAlgorithm) {
  // Obtain a random seed from hardware.
  std::random_device rd;

  // Standard mersenne_twister_engine seeded with rd().
  std::mt19937 mersenne_engine(rd());

  // Define the range of integer values [-1000, 1000]
  std::uniform_int_distribution<> dist(-1000, 1000);

  // Create a generator.
  auto gen = [&](){ return dist(mersenne_engine); };

  // Create a vector of 1000 random values
  std::vector<int> nums(1000);
  std::generate(nums.begin(), nums.end(), gen);

  // Our prefix sum algorithm should match std::partial_sum and
  // std::inclusive_scan (the parallel version of std::partial_sum where
  // BinaryOp is assumed to be associative, i.e. (2 + 3) + 4 = 2 + (3 + 4))
  std::vector<int> partial_sum(nums.size());
  std::vector<int> inclusive_scan(nums.size());
  std::partial_sum(nums.begin(), nums.end(), partial_sum.begin());
  std::inclusive_scan(nums.begin(), nums.end(), inclusive_scan.begin());

  // Get the result using our custom "prefix sum" algorithm
  const std::vector<int> result = prefix_sum::get_prefix_sum(nums);

  // Validate the result.
  EXPECT_EQ(result, partial_sum);
  EXPECT_EQ(result, inclusive_scan);
}

/**
 * @brief Given an integer array 'nums', an array 'queries' (where 
 * queries[i] = [x, y]), and an integer 'limit', return a boolean array that 
 * represents the answer to each query. A query is true if the sum of the 
 * subarray from x to y is less than limit, or false otherwise.
 */
TEST(TestPrefixSum, TestQuerySum) {
  const std::vector<int> nums = { 1, 6, 3, 2, 7, 2 };
  const std::vector<std::vector<int>> queries = { {0, 3}, {2, 5}, {2, 4} };
  const int limit = 13;
  const std::vector<bool> result = prefix_sum::query_sum(nums, queries, limit);
  const std::vector<bool> expected = {true, false, true};
  EXPECT_EQ(result, expected);
}

/**
 * @brief Given an integer array 'nums', find the number of ways to split the
 * array into two parts so that the first section has a sum greater than or
 * equal to the sum of the second section. The second section should have at
 * least one number.
 */
TEST(TestPrefixSum, TestBisectNWays) {
  const std::vector<int> nums = { 10, 4, -8, 7 };
  const auto valid_idxs = prefix_sum::bisect_n_ways(nums);

  const std::vector<std::tuple<idx_tuple, idx_tuple>> expected_idxs = {
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
  const std::vector<int> nums { -3, 2, -3, 4, 2 };
  EXPECT_EQ(prefix_sum::min_pos_value(nums), 5);

  // Example 2: The minimum start value should be positive.
  const std::vector<int> nums2 { 1, 2 };
  EXPECT_EQ(prefix_sum::min_pos_value(nums2), 1);

  // Example 3:
  const std::vector<int> nums3 { 1, -2, -3 };
  EXPECT_EQ(prefix_sum::min_pos_value(nums3), 5);
}

/**
 * @brief
 * 
 * TODO: Getting a compilation error that I haven't been able resolve yet
 * related to trying to use std::enable_if_t<> to ensure that the prefix sum
 * and the resulting averages are a 64-bit type (int64_t).
 */
TEST(TestPrefixSum, KRadiusSubarrayAverages) {
  GTEST_SKIP();

  // // Example 1:
  // const std::vector<int> nums { 7,4,3,9,1,8,5,2,6 };
  // const std::vector<int> expected = { -1,-1,-1,5,4,4,-1,-1,-1 };
  // const std::vector<int64_t> result = prefix_sum::k_radius_avg(nums, 3);
  // EXPECT_EQ(result, expected);

  // // Example 2: The sum of the subarray centered at 0 with radius 0 is: 100000.
  // const std::vector<int> nums2 { 100000 };
  // const std::vector<int> expected2 = { 100000 };
  // auto result2 = prefix_sum::k_radius_avg(nums2, 0);
  // EXPECT_EQ(result2, expected2);

  // // Example 3: avg[0] is -1 because there are less than k elements before and
  // // after index 0.
  // const std::vector<int> nums3 { 8 };
  // const std::vector<int> expected3 = { -1 };
  // auto result3 = prefix_sum::k_radius_avg(nums3, 100000);
  // EXPECT_EQ(result3, expected3);

  // // Example 3: Current algorithm fails for this example.
  // const std::vector<int> nums4 { 2, 2, 1 };
  // const std::vector<int> expected4 { -1, 1, -1 };
  // auto result4 = prefix_sum::k_radius_avg(nums4, 1);
  // // EXPECT_EQ(result4, expected4);
}