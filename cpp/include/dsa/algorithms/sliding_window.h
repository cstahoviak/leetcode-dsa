#pragma once
/**
 * @file sliding_window.h
 * @author your name (you@domain.com)
 * @brief 
 * @date 2024-05-08 
 */

#include <algorithm>
// Include to get 'size_t'
#include <cstddef>

namespace dsa::algorithms::sliding_window
{
  /**
   * @brief Given an array of positive integers and an integer 'sum', find the 
   * length of the longest subarray whose sum is less than or equal to 'sum'.
   * 
   * @tparam T 
   * @param arr 
   * @param sum 
   * @return size_t 
   */
  template <typename T>
  size_t longest_subarray(std::vector<T> arr, T sum) {
    size_t left = 0;
    T current_sum = 0;
    size_t max_length = 0;

    for (size_t right = 0; right < arr.size(); right++) {
      current_sum += arr[right];
      while (current_sum > sum) {
        current_sum -= arr[left];
        left++;
      }
      max_length = std::max(max_length, right - left + 1);
    }
    return max_length;
  }

} // end namespace dsa::algorithms::sliding_window
