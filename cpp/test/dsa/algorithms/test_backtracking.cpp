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