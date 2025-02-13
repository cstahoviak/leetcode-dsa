/**
 * @file binary_search.h
 * @author Carl Stahoviak
 * @brief Binary search algorithms.
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

#include <algorithm>  // std::sort
#include <cmath>      // std::ceil
#include <cstddef>    // size_t
#include <execution>  // std::execution (for std::transform_reduce)
#include <numeric>    // std::inclusive_scan
#include <vector>

namespace dsa::algorithms::binary_search
{
  /**
   * @brief 35. Search Insert Position (Easy)
   * https://leetcode.com/problems/search-insert-position/
   * 
   * Given a sorted array of distinct integers and a target value, return the
   * index if the target is found. If not, return the index where it would be if
   * it were inserted in order.
   * 
   * This algorithm is equivalent to std::lower_bound.
   * 
   * @tparam T 
   * @param nums A sorted input array of values.
   * @param target The target value.
   * @return size_t The index location of target if target is in 'nums', else
   * the insertion index such that inserting 'target' would preserve the
   * ordering of 'nums'.
   */
  template<typename T>
  size_t search_insert(const std::vector<T>& nums, T target) {
    // The STL's built-in function to accomplish the same thing.
    // return std::lower_bound(nums.cbegin(), nums.cend(), target);

    // left and right represent the inclusive bounds of the current search space
    int left = 0;
    int right = int(nums.size()) - 1;

    while (left <= right) {
      // Calculate the middle of the current search space.
      // Equivalent to (left + right) / 2, but prevents overflow.
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        // The element has been found, return its index.
        return mid;
      }

      // Halve the search space by updating either left or right.
      if (nums[mid] > target) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    
    // Target is not in arr, but left is at the insertion point
    return left;
  }

  /**
   * @brief 2389. Longest Subsequence with Limited Sum (Easy)
   * https://leetcode.com/problems/longest-subsequence-with-limited-sum/
   * 
   * Fiven an integer array nums of length n, and an integer array queries of
   * length m.
   * 
   * Return an array result of length m where result[i] is the maximum size of a
   * subsequence that you can take from nums such that the sum of its elements
   * is less than or equal to queries[i].
   * 
   * @tparam T 
   * @param nums 
   * @param queries 
   * @return std::vector<T> 
   */
  template<typename T>
  std::vector<T> answer_queries(
    std::vector<T>& nums,
    const std::vector<T>& queries)
  {
    // Start by sorting nums in place.
    // TODO: I don't understand why this doesn't mess things up if we are
    // looking for the maximum size of a "subsequence" of 'nums', and a
    // subsequence, dy definition, preserves the original order of the elements.
    std::sort(nums.begin(), nums.end());

    // Next, create a prefix sum array for nums (a prefix sum array is strictly
    // increasing, and thus will always be sorted).
    std::vector<T> prefix_sum(nums.size());
    std::inclusive_scan(nums.cbegin(), nums.cend(), prefix_sum.begin());
    LOG("nums.size(): " << nums.size() << ",\t prefix_sum.size(): " <<
      prefix_sum.size());

    // For each query, use binary search to find its insertion point in the
    // prefix sum array.
    std::vector<T> result(queries.size());
    size_t idx{0};
    for ( const T& query : queries ) {
      result[idx] = std::distance(prefix_sum.cbegin(),
        std::upper_bound(prefix_sum.cbegin(), prefix_sum.cend(), query));
      idx++;
    }

    return result;
  }

  /**
   * @brief 1283. Find the Smallest Divisor Given a Threshold (Medium)
   * https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
   * 
   * Given an array of integers 'nums' and an integer 'threshold', choose a
   * positive integer divisor, divide all the array by it, and sum the 
   * division's result. Find the smallest divisor such that the result mentioned
   * above is less than or equal to threshold.
   * 
   * Each result of the division is rounded to the nearest integer greater than
   * or equal to that element, eg 7/3 = 3 and 10/2 = 5.
   * 
   * @tparam T 
   * @param nums 
   * @param threshold 
   * @return T 
   */
  template<typename T>
  uint32_t smallest_divisor(const std::vector<T>& nums, T threshold) {
    // 1. How can we choose the bounds of our binary search?
    // 1a. If divisor is a positive integer, divisor=1 will yeild the maximum
    //  possible value of sum(nums / divisor)
    // 1b. Given that the threshold will always be greater than or equal to the
    //  length of nums, we do not need to search for a divisor greater than
    //  max(nums).
    uint32_t left = 1;
    uint32_t right = *std::max_element(nums.cbegin(), nums.cend());

    // Define our custom division function to meet the problem requirements.
    auto divide = [](T& num, uint32_t& divisor) -> int { 
      // return std::ceil((1.0 * num) / scalar);
      return (num + divisor - 1) / divisor;
    };

    // Precompute the sum of nums (std::reduce is parallelizable unlike std::accumulate)
    // T sum = std::reduce(nums.cbegin(), nums.cend(), 0);

    while ( left <= right ) {
      // Calculate the middle of the current search space
      uint32_t mid = left + (right - left) / 2;

      // Divide the sum of nums by mid - this WON'T work because integer
      // division must be performed on EACH element. I think this means that
      // this particular type of division is non associative?
      // uint32_t sum_of_divisions = sum / mid;

      // Compute the "sum of divisions" if divisor = mid
      LOG("left: " << left << ",\tright: " << right << ",\tmid: " << mid);
      uint32_t sum_of_divisions = std::transform_reduce(
        std::execution::par,          // execution policy: parallel
        nums.cbegin(), nums.cend(),   // input range
        0,                            // initial value of sum
        std::plus<int>(),             // reduction operation: addition
        // transformation func: division by scalar
        [&divide, &mid](T val) { return divide(val, mid); } 
      );

      // TODO: Not sure why this isn't matching the result of transform_reduce
      uint32_t sum_of_divisions2 = std::reduce(
        nums.cbegin(), nums.cend(),
        0,
        [&divide, &mid](uint32_t acc, T num) { return acc + divide(num, mid); }
      );

      LOG("\tsum1: " << sum_of_divisions << ",\tsum2: " << sum_of_divisions2);

      if ( sum_of_divisions <= threshold ) {
        // The the sum is less than or equal to the threshold value, then this
        // divisor may be our answer, but we also need to try smaller divisors.
        right = mid - 1;
      }
      else {
        // Otherwise, the sum exceeds the threshold, and we need a larger
        // divisor, so eliminate the left half of the remain search space.
        left = mid + 1;
      }
    }

    // We never matched the threshold value exactly, but our search space size
    // cannot be reduced any further.
    return left;
  }

  /**
   * @brief 1231. Divide Chocolate (Hard)
   * https://leetcode.com/problems/divide-chocolate/
   * 
   * @tparam T 
   * @param sweetness 
   * @param k 
   * @return T 
   */
  template<typename T>
  T maximize_sweetness(const std::vector<T>& sweetness, int k) {
    return 0;
  }

  /**
   * @brief 410. Split Array Largest Sum (Hard)
   * https://leetcode.com/problems/split-array-largest-sum/
   * 
   * @tparam T 
   * @param nums 
   * @param k 
   * @return T 
   */
  template<typename T>
  T split_array(const std::vector<T>& nums, int k) {
    return 0;
  }
}