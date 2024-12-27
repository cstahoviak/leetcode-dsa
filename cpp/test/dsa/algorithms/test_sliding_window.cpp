/**
 * @file test_sliding_window.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for Sliding Window algorithms.
 * @version 0.1
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "dsa/algorithms/sliding_window.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;


/**
 * @brief The Longest Subarray algorithm returns the longest subarray in the
 * input array that's less than the provided sum.
 */
TEST(TestSlidingWindow, TestLongestSubarray) {
  std::vector<int> v = { 3, 1, 2, 7, 4, 2, 1, 1, 5 };
  int sum = 9;
  EXPECT_EQ(sliding_window::longest_subarray(v, sum), 4);
}

/**
 * @brief The Flip One algorithm will flip one zero in a string of ones and
 * zeros to create the longest subarray of ones.
 */
TEST(TestSlidingWindow, TestFlipOne) {
  std::string s = "11001011";
  EXPECT_EQ(sliding_window::flip_one(s), 4);
}

/**
 * @brief The Largest Sum algorithm will find the largest sum of a fixed-size
 * window.
 */
TEST(TestSlidingWindow, TestLargestSum) {
  std::vector<int> nums { 3, -1, 4, 12, -8, 5, 6 };
  int window_size = 4;
  EXPECT_EQ(sliding_window::largest_sum(nums, window_size), 18);
}

/**
 * @brief The Max Average Subarray algorithm finds the fixed-sized subarray with
 * the maximum average value.
 */
TEST(TestSlidingWindow, TestMaxAverageSubarray) {
  std::vector<int> nums = { 4, 0, 4, 3, 3 };
  int window_size = 5;
  EXPECT_EQ(sliding_window::max_avg_subarray(nums, window_size), 2.8);
}

/**
 * @brief Given a binary array 'nums' and integer 'k', return the maximum number
 * of consecutive 1's in the array if you can flip at most k 0's.
 * 
 * In other words, what is the largest subarray that contains at most k zeros?
 */
TEST(TestSlidingWindow, TestMaxConsecutiveOnes) {
  std::vector<int> nums = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
  int k = 3;
  EXPECT_EQ(sliding_window::max_consecutive_ones(nums, k), 10);
}
