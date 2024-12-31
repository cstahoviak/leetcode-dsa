#pragma once
/**
 * @file prefix_sum.h
 * @author Carl Stahoviak
 * @brief Implementations of the "prefix sum" algorithm.
 * @date 2024-05-24
 * 
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using idx_tuple = std::tuple<size_t, size_t>;

namespace dsa::algorithms::prefix_sum
{
  /**
   * @brief Returns the "prefix sum" of the input array. The prefix sum at the
   * ith element is defined as sum(nums[0] + ... + nums[i-1] + nums[i]).
   * 
   * Note: It is possible that the sum of all the elements does not fit in a
   * 32-bit integer type. Be sure to use a 64-bit integer type for the prefix
   * sum array.
   * 
   * @tparam T 
   * @param nums The input array.
   * @return std::vector<T> The prefix sum array.
   */
  template <typename T, std::enable_if_t<std::is_integral<T>::value>>
  std::vector<int64_t> get_prefix_sum(const std::vector<T>& nums) {
    // Create the "prefix sum" array, costs O(n)
    std::vector<int64_t> prefix_sum(nums.size());
    prefix_sum[0] = nums[0];
    for (size_t idx = 1; idx < nums.size(); idx++) {
      prefix_sum[idx] = prefix_sum[idx - 1] + nums[idx];
    }
    return prefix_sum;
  }

  template <typename T>
  std::vector<T> get_prefix_sum(const std::vector<T>& nums) {
    // Create the "prefix sum" array, costs O(n)
    std::vector<T> prefix_sum(nums.size());
    prefix_sum[0] = nums[0];
    for (size_t idx = 1; idx < nums.size(); idx++) {
      prefix_sum[idx] = prefix_sum[idx - 1] + nums[idx];
    }
    return prefix_sum;
  }

  /**
   * @brief Given an integer array 'nums', an array 'queries' (where 
   * queries[i] = [x, y]), and an integer 'limit', return a boolean array that 
   * represents the answer to each query. A query is true if the sum of the 
   * subarray from x to y is less than limit, or false otherwise.
   * 
   * @tparam T 
   * @param nums 
   * @param queries 
   * @param limit 
   * @return std::vector<bool> 
   */
  template <typename T> 
  std::vector<bool> query_sum(const std::vector<T>& nums,
                              const std::vector<std::vector<int>>& queries,
                              const T limit) {
    // Create the prefix sum array
    const auto prefix_sum = get_prefix_sum(nums);

    size_t idx = 0;
    std::vector<bool> result(queries.size());
    for (const std::vector<int>& query_idx : queries) {
      T subarray_sum = prefix_sum[query_idx[1]] - prefix_sum[query_idx[0]] + 
        nums[query_idx[0]];
      result[idx] = subarray_sum < limit;
      idx++;
    }

    return result;
  }

  /**
   * @brief Given an integer array 'nums', find the number of ways to split the
   * array into two parts so that the first section has a sum greater than or
   * equal to the sum of the second section. The second section should have at
   * least one number.
   * 
   * TODO: We can improve the space complexity of this algorithm to O(1) by
   * choosing not to pre-compute the prefix-sum. Instead, we can compute the sum
   * of the input array - which costs O(n), same as computing the prefix-sum
   * array - and as we iterate over nums, we simply add the current value to
   * a 'left_sum' value and then compute the 'right_sum' value as
   * 'sum - left_sum'.
   * 
   * @tparam T 
   * @param nums 
   * @return std::vector<std::tuple<int>> 
   */
  template <typename T>
  std::vector<std::tuple<idx_tuple, idx_tuple>> bisect_n_ways(
    const std::vector<T>& nums)
  {
    // Create the prefix sum array
    const auto prefix_sum = get_prefix_sum(nums);

    // Create the valid bisection indices
    std::vector<std::tuple<idx_tuple, idx_tuple>> valid_idxs;
    // Only iterate up to nums.size()-2 because a valid subarray must contain at
    // least one value, and the bisection at index nums.size()-2 represents the
    // final valid bisection.
    for (size_t idx = 0; idx < nums.size() - 1; idx++) {
      T lsubarray_sum = prefix_sum[idx];
      T rsubarray_sum = prefix_sum.back() - prefix_sum[idx];
      if (lsubarray_sum >= rsubarray_sum) {
        valid_idxs.push_back({{0, idx}, {idx + 1, nums.size() - 1}});
      }
    }
    return valid_idxs;
  }

  /**
   * @brief Given an array of integers 'nums', return the minimum positive
   * value such that the step-by-step sum of 'value + nums' is never less than
   * 1.
   * 
   * @tparam T 
   * @param nums 
   * @return size_t 
   */
  template<typename T>
  size_t min_pos_value(const std::vector<T>& nums) {
    // Create the prefix sum array
    const auto prefix_sum = get_prefix_sum(nums);

    // Find the minimum element in the prefix sum array
    T min = *std::min_element(prefix_sum.begin(), prefix_sum.end());

    // The minimum start value should be positive.
    return std::max(1 - min, 1);
  }

  /**
   * @brief You are given a 0-indexed array nums, and an integer k.
   * 
   * The k-radius average for a subarray of nums centered at some index i with
   * the radius k is the average of all elements in nums between the indices
   * i - k and i + k (inclusive). If there are less than k elements before or
   * after the index i, then the k-radius average is -1. 
   * 
   * Build and return an array 'avgs' of length n where avgs[i] is the k-radius
   * integer average (truncated) for the subarray centered at index i.
   * 
   * TODO: This implementation is incorrect. See Example 4 in
   * TestPrefixSum::KRadiusSubarrayAverages for a failing test case
   * 
   * @tparam T 
   * @param nums 
   * @param k 
   * @return std::vector<T> 
   */
  // template<typename T>
  template<typename T, std::enable_if_t<std::is_integral<T>::value>>
  std::vector<int64_t> k_radius_avg(const std::vector<T>& nums, int k) {
    // Deal with the radius-0 case.
    if ( k == 0 ) {
      std::vector<int64_t> avgs64(nums.size());
      std::transform(nums.begin(), nums.end(), avgs64.begin(), 
        [](int x) { return static_cast<int64_t>(x); });
      return avgs64;

      // return static_cast<std::vector<std::int64_t>>(nums);
    }

    // Deal with the case where the size of nums is insufficient.
    // TODO: This conditional is wrong.
    if ( nums.size() / 2 <= k ) {
      std::vector<int64_t> avgs64(nums.size(), -1);
      return avgs64;
    }

    // All other cases: initialize the return vector with -1s
    std::vector<int64_t> avgs64(nums.size(), -1);

    // Create the prefix sum array
    const auto prefix_sum = get_prefix_sum(nums);

    // Manually compute the first non-negative average.
    const size_t window_sz = 2*k + 1;
    avgs64.at(k) = prefix_sum.at(2*k) / window_sz;

    // Compute the remaining subarray averages
    for ( size_t idx = k + 1; idx < nums.size() - k; idx++ ) {
      // Compute the sum of the subarray centered at nums[idx]
      avgs64.at(idx) = (prefix_sum.at(idx + k) - prefix_sum.at(idx - (k+1))) / 
        window_sz;
    }

    return avgs64;
  }
} // end namespace dsa::algorithms::prefix_sum