/**
 * @file test_binary_search.cpp
 * @author Carl Staoviak
 * @brief Unit tests for binary search algorithms.
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/algorithms/binary_search.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

TEST(TestBinarySearch, TestSearchInsertionPoint) {
  // Define test inputs
  const std::vector<int> nums = { 1, 3, 5, 6 };
  const int target1 = 5, target2 = 2, target3 = 7;

  EXPECT_EQ(binary_search::search_insert(nums, target1), 2);
  EXPECT_EQ(binary_search::search_insert(nums, target2), 1);
  EXPECT_EQ(binary_search::search_insert(nums, target3), 4);

  // Use the STL's built-in binary search algorithm as a second check.
  const auto expected1 = std::distance(nums.begin(),
    std::lower_bound(nums.cbegin(), nums.cend(), target1));
  const auto expected2 = std::distance(nums.begin(),
    std::lower_bound(nums.cbegin(), nums.cend(), target2));
  const auto expected3 = std::distance(nums.begin(),
    std::lower_bound(nums.cbegin(), nums.cend(), target3));

  EXPECT_EQ(binary_search::search_insert(nums, target1), expected1);
  EXPECT_EQ(binary_search::search_insert(nums, target2), expected2);
  EXPECT_EQ(binary_search::search_insert(nums, target3), expected3);
}

TEST(TestBinarySearch, TestAnswerQueries) {
  // Define test data (nums will be modified in-place).
  std::vector<int> nums1 = { 4, 5, 2, 1 };
  std::vector<int> nums2 = { 2, 3, 4, 5 };
  const std::vector<int> queries1 = { 3, 10, 21 };
  const std::vector<int> queries2 = { 1 };

  // Define the expected results
  const std::vector<int> expected1 = { 2, 3, 4 };
  const std::vector<int> expected2 = { 0 };

  EXPECT_EQ(binary_search::answer_queries(nums1, queries1), expected1);
  EXPECT_EQ(binary_search::answer_queries(nums2, queries2), expected2);
}

TEST(TestBinarySearch, TestSmallestDivisor) {
  // Define test data
  const std::vector<int> nums1 = { 1, 2, 5, 9 };
  const std::vector<int> nums2 = { 44, 22, 33, 11, 1 };

  EXPECT_EQ(binary_search::smallest_divisor(nums1, 6), 5);
  EXPECT_EQ(binary_search::smallest_divisor(nums2, 5), 44);
}

TEST(TestBinarySearch, TestMaximizeSweetness) {
  // Define test data
  const std::vector<int> sweetness1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  const std::vector<int> sweetness2 = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };
  const std::vector<int> sweetness3 = { 1, 2, 2, 1, 2, 2, 1, 2, 2 };

  EXPECT_EQ(binary_search::maximize_sweetness(sweetness1, 5), 6);
  EXPECT_EQ(binary_search::maximize_sweetness(sweetness2, 8), 1);
  EXPECT_EQ(binary_search::maximize_sweetness(sweetness3, 2), 5);
}

TEST(TestBinarySearch, TestSplitArray) {
  // Define test data
  const std::vector<int> nums1 = { 7, 2, 5, 10, 8 };
  const std::vector<int> nums2 = { 1, 2, 3, 4, 5 };

  EXPECT_EQ(binary_search::split_array(nums1, 2), 18);
  EXPECT_EQ(binary_search::split_array(nums2, 2), 9);
}