/**
 * @file test_two_pointers.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "dsa/algorithms/two_pointers.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms::two_pointers;


/**
 * @brief The Two Sum algorithm is true if there is at least one pair of values
 * that sums to the the target sum; false otherwise.
 * 
 */
TEST(TestTwoPointers, TestTwoSum) {
  // Define the array of values
  std::array<int, 10> values = { 1, 6, 10, 3, 7, 8, 0, 12, 2, 5 };

  // The two-sum algorithm requires a sorted a array
  std::sort(values.begin(), values.end());

  // Define the target sum
  int target_sum_valid = 15;
  int target_sum_invalid = 23;

  // Solve the two-sum problem with a static array
  EXPECT_TRUE(two_sum(values, target_sum_valid));
  EXPECT_FALSE(two_sum(values, target_sum_invalid));

  // Solve the two-sum problem with a vector (dynamic array)
  std::vector<int> vec(values.begin(), values.end());
  EXPECT_TRUE(two_sum(vec, target_sum_valid));
  EXPECT_FALSE(two_sum(vec, target_sum_invalid));
}

/**
 * @brief The Combine Sorted algortihm combines two sorted arrays and does NOT
 * remove repeat elements.
 */
TEST(TestTwoPointers, TestCombineSorted) {
  // Define the arrays to be combined
  std::array<int, 5> arr1 = { 4, 0, 6, 1, 2 };
  std::array<int, 6> arr2 = { 3, 5, 7, 9, 8, 0};

  // Sort the arrays
  std::sort(arr1.begin(), arr1.end());
  std::sort(arr2.begin(), arr2.end());

  // Solve using static arrays
  std::array<int, 11> expected_arr = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto result_arr = combine_sorted(arr1, arr2);
  EXPECT_EQ(result_arr, expected_arr);

  // Solve using vectos (dynamic arrays)
  std::vector<int> vec1(arr1.begin(), arr1.end());
  std::vector<int> vec2(arr2.begin(), arr2.end());
  std::vector<int> expected_vec(expected_arr.begin(), expected_arr.end());
  auto result2 = combine_sorted(vec1, vec2);
  EXPECT_EQ(result2, expected_vec);
}

TEST(TestTwoPointers, TestIsSubsequence) {
  std::string s = "ace";
  std::string t = "aabcdfgahcie";

  // Expect true because 'ace' is in 'aAbCdfgahciE'
  EXPECT_TRUE(is_subsequence(s, t));
}

TEST(TestTwoPointers, TestReverse) {
  std::string str = "Stahoviak";
  // reverse() operates on the string in-place
  reverse(str);
  EXPECT_EQ(str, std::string{"kaivohatS"});
}

TEST(TestTwoPointers, TestSortedSquares) {
  // Define the input array
  std::array<int, 6> arr = { -7, -3, 2, 3, 11, 12 };

  // Solve using arrays
  std::array<int, 6> expected_arr = { 4, 9, 9, 49, 121, 144 };
  std::array<int, 6> result_arr = sorted_squares(arr);
  EXPECT_EQ(result_arr, expected_arr);

  // Solve using vectos (dynamic arrays)
  std::vector<int> vec(arr.begin(), arr.end());
  std::vector<int> expected_vec(expected_arr.begin(), expected_arr.end());
  std::vector<int> result_vec = sorted_squares(vec);
  EXPECT_EQ(result_vec, expected_vec);
}
