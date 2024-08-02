/**
 * @file test_prefix_sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "dsa/algorithms/prefix_sum.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

TEST(TestPrefixSum, TestPrefixSumAlgorithm) {
  GTEST_SKIP();
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
