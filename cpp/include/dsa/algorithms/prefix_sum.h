#pragma once
/**
 * @file prefix_sum.h
 * @author Carl Stahoviak
 * @brief Implementations of the "prefix sum" algorithm.
 * @date 2024-05-24
 * 
 */

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
   * @tparam T 
   * @param nums The input array.
   * @return std::vector<T> The prefix sum array.
   */
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
    const std::vector<T> prefix_sum = get_prefix_sum(nums);

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
    std::vector<T> prefix_sum = get_prefix_sum(nums);

    // Create the valid bisection indices
    std::vector<std::tuple<idx_tuple, idx_tuple>> valid_idxs;
    // Only iterate up nums.size()-2 because a valid subarray must contain at
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
} // end namespace dsa::algorithms::prefix_sum