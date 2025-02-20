/**
 * @file test_backtracking.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for backtracking algorithms.
 * @version 0.1
 * @date 2025-02-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/algorithms/backtracking.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

TEST(TestBacktracking, TestAllPathsFromSourceToTarget) {
  // Define the test data
  const std::vector<std::vector<int>> graph1 = { {1,2}, {3}, {3}, {} };
  const std::vector<std::vector<int>> graph2 = { {4,3,1},{3,2,4},{3},{4},{} };

  // Define the expected results
  const std::vector<std::vector<int>> expected1 = { {0,1,3},{0,2,3} };
  const std::vector<std::vector<int>> expected2 = { 
    {0,4}, {0,3,4}, {0,1,3,4}, {0,1,2,3,4}, {0,1,4}
  };

  // Get the results
  const auto result1 = backtracking::all_paths(graph1);
  const auto result2 = backtracking::all_paths(graph2);

  EXPECT_EQ(result1.size(), expected1.size());
  for ( const std::vector<int>& path : result1 ) {
    EXPECT_NE(std::find(expected1.cbegin(), expected1.cend(), path),
      expected1.cend());
  }
  
  EXPECT_EQ(result2.size(), expected2.size());
  for ( const std::vector<int>& path : result2 ) {
    EXPECT_NE(std::find(expected2.cbegin(), expected2.cend(), path),
      expected2.cend());
  }
}

TEST(TestBacktracking, TestLetterCombinations) {
  // Define the test data
  const std::vector<std::string> digits = { "23", "", "2" };
  const std::vector<std::vector<std::string>> expected {
    {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"},
    {},
    {"a", "b", "c"}, 
  };

  size_t idx{0};
  for ( const std::string& d : digits ) {
    const auto result = backtracking::letter_combinations(d);

    EXPECT_EQ(result.size(), expected[idx].size());
    for ( const std::string& combination : expected[idx] ) {
      // Verify that this combination exists in the result.
      EXPECT_NE(std::find(result.cbegin(), result.cend(), combination),
        result.cend());
    }
    idx++;
  }
}

TEST(TestBacktracking, TestGenerateParenthesis) {
  // Define the expected values
  const std::vector<int> n_parenthesis = {3, 1};
  const std::vector<std::vector<std::string>> expected = {
    {"((()))", "(()())", "(())()", "()(())", "()()()"},
    {"()"}
  };

  for ( size_t idx = 0; idx < expected.size(); idx++ ) {
    const auto result = backtracking::generate_parenthesis(n_parenthesis[idx]);
    EXPECT_EQ(result.size(), expected[idx].size());
    for (const std::string& str : result ) {
      // Verify that each string in the result vec exists in the expected vec.
      EXPECT_NE(std::find(expected[idx].cbegin(), expected[idx].cend(), str),
        expected[idx].cend());
    }
  }
}

TEST(TestBacktracking, TestNumbersWithSameConsecutiveDifference) {
  GTEST_SKIP();

  // Define the expected values
  const std::vector<int> n_vec = {3, 2};
  const std::vector<int> k_vec = {7, 1};
  const std::vector<std::vector<int>> expected = {
    { 181, 292, 707, 818, 929 },
    { 10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98 }
  };

  for ( size_t idx = 0; idx < expected.size(); idx++ ) {
    const auto result = backtracking::consecutive_diff(n_vec[idx], k_vec[idx]);
    EXPECT_EQ(result.size(), expected[idx].size());
    for (const int& val : result ) {
      // Verify that each value in the result vec exists in the expected vec.
      EXPECT_NE(std::find(expected[idx].cbegin(), expected[idx].cend(), val),
        expected[idx].cend());
    }
  }
}

TEST(TestBacktracking, TestCombinationSum3) {
  // Define the expected values
  const std::vector<int> k_vec = {3, 3, 4, 2};
  const std::vector<int> n_vec = {7, 9, 1, 6};
  const std::vector<std::vector<std::vector<int>>> expected = {
    {{1, 2, 4}},
    {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}},
    {},
    {{1, 5}, {2, 4}}
  };

  for ( size_t idx = 0; idx < expected.size(); idx++ ) {
    const auto result = backtracking::combination_sum_3(k_vec[idx], n_vec[idx]);
    EXPECT_EQ(result.size(), expected[idx].size());
    for (const std::vector<int>& val : result ) {
      // Verify that each value in the result vec exists in the expected vec.
      EXPECT_NE(std::find(expected[idx].cbegin(), expected[idx].cend(), val),
        expected[idx].cend());
    }
  }
}
