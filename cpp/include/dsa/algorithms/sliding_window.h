#pragma once
/**
 * @file sliding_window.h
 * @author your name (you@domain.com)
 * @brief 
 * @date 2024-05-08 
 */

#include "dsa/algorithms/sliding_window_algos.h"

#include <algorithm>
// Include to get 'size_t'
#include <cstddef>
#include <string>

namespace dsa::algorithms::sliding_window
{
// Short-hand for the back-end two-pointers namespace
  namespace sw = dsa::algorithms::_sliding_window;

  /**
   * @brief Given an array of positive integers and an integer 'sum', find the 
   * length of the longest subarray whose sum is less than or equal to 'sum'.
   * 
   * @tparam T 
   * @param arr A vector of positive integers.
   * @param sum
   * @return size_t The length of the longest subarray.
   */
  template <typename T>
  size_t longest_subarray(std::vector<T>& vec, T sum) {
    size_t left = 0;
    T current_sum = 0;
    size_t max_length = 0;

    for (size_t right = 0; right < vec.size(); right++) {
      current_sum += vec[right];
      while (current_sum > sum) {
        current_sum -= vec[left];
        left++;
      }
      max_length = std::max(max_length, right - left + 1);
    }
    return max_length;
  }

  /**
   * @brief You are given a binary string s containing only "0" and "1", choose
   * up to one "0" and flip it to a "1". Return the length of the longest
   * substring achievable that contains only "1"?
   * 
   * In other words, what is the longest substring that contains at most one
   * "0"?
   * 
   * @param s A string containing only zeros and ones, e.g. "010011010011".
   * @return size_t The length of the longest subarray.
   * 
   * TODO: tempaltize this to accept either a std::string or binary vector.
   */
  size_t flip_one(std::string& s) {
    return sw::_max_consecutive_ones(s.begin(), s.end(), '0', 1);
  }

  /**
   * @brief Given an array of positive integers 'nums' and an integer 'prod', 
   * return the number of subarrays where the product of all the elements in
   * the subarray is strictly less than 'prod'.
   * 
   * @param nums A vector of positive integers. 
   * @param prod The product that defines a valid subarray - the product of all
   *  elements in the subarray must be less or equal to prod.
   * @return size_t The number of valid subarrays.
   */
  size_t num_subarrays_prod_lt(std::vector<int>& nums, int prod) {
    size_t left = 0;
    int current_prod = 1;
    size_t n_subarrays = 0;

    for (size_t right = 0; right < nums.size(); right++) {
      current_prod *= nums[right];

      // If the product of the current window is greater than prod, we need to
      // shrink the window and increment the left pointer until the current
      // window product is valid.
      while (current_prod >= prod) {
        current_prod /= nums[left];
        left++;
      }
      // Each time a new element is added on the right, we increment the number
      // of valid subarrays that end at the current right index. And the number
      // of ~unaccounted for~ valid subarrays will always be the size of the
      // window itself.
      n_subarrays += (right - left + 1);
    }
    return n_subarrays;
  }

  /**
   * @brief Given an array 'nums' and a 'window_size', return the sum of the
   * subarray (of length window_size) with the largest sum.
   * 
   * @tparam T 
   * @param nums A vector of values.
   * @param window_size The window size.
   * @return T The sum of the of subarray with the largest sum.
   */
  template <typename T>
  T largest_sum(std::vector<T>& nums, size_t window_size) {
    T current_sum = 0;

    // Set the sum of the first window as the current max sum
    for (size_t idx = 0; idx < window_size; idx++) {
      current_sum += nums[idx];
    }
    T max_sum = current_sum;

    for (size_t right = window_size; right < nums.size(); right++) {
      // Move the window one to the right by adding the next element to the
      // right and subtracting the left element.
      current_sum += nums[right] - nums[right - window_size];

      // Update the current maximum sum
      max_sum = std::max(max_sum, current_sum);
    }
    return max_sum;
  }

  /**
   * @brief Max Average Subarray I (Easy)
   * https://leetcode.com/problems/maximum-average-subarray-i/
   * 
   * Find a contiguous subarray whose length is equal to 'window_size'
   * that has the maximum average value and return this value.
   * 
   * @tparam T 
   * @param nums An array of values.
   * @param window_size The window size.
   * @return double The average of the largest subarray of size 'window_size' in
   *  'nums'.
   */
  template <typename T>
  double max_avg_subarray(std::vector<T>& nums, int window_size) {
    // Get the average of the first window
    T current_sum = 0;
    for (size_t idx = 0; idx < window_size; idx++) {
      current_sum += nums[idx];
    }
    T max_sum = current_sum;

    for (size_t right = window_size; right < nums.size(); right++) {
    // Update the current window sum
      current_sum += nums[right] - nums[right - window_size];

    // Udpate the max avg
    max_sum = std::max(max_sum, current_sum);
    }
    return (double)max_sum / (double)window_size;
  }

  /**
   * @brief Max Consecutive Ones III (Medium)
   * https://leetcode.com/problems/max-consecutive-ones-iii/
   * 
   * Given a binary array 'nums' and integer 'k', return the maximum
   * number of consecutive 1's in the array if you can flip at most k 0's.
   * 
   * In other words, what is the largest subarray that contains at most k zeros?
   * 
   * Assumptions:
   *  - 0 <= k <= nums.size()
   * 
   * @param nums The binary array (consists of only ones and zeros).
   * @param k The number of zeros that can be flipped.
   * @return size_t The length of the largest subarray of ones when k zeros are
   *  flipped to ones.
   */
  size_t max_consecutive_ones(std::vector<int>& nums, int k) {
    return sw::_max_consecutive_ones(nums.begin(), nums.end(), 0, k);
  }
} // end namespace dsa::algorithms::sliding_window