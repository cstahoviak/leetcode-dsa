#pragma once
/**
 * @file greedy.h
 * @author Carl Stahoviak
 * @brief Greedy algorithms.
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <queue>
#include <vector>

namespace dsa::algorithms::greedy
{
  /**
   * @brief 1323. Maximum 69 Number (Easy)
   * https://leetcode.com/problems/maximum-69-number/
   * 
   * You are given a positive integer 'num' consisting only of digits 6
   * and 9.
   * 
   * Return the maximum number you can get by changing at most one digit (6 
   * becomes 9, and 9 becomes 6).
   * 
   * @param num The input number.
   * @return int The output value with at most one changed digit.
   */
  int maximum_69_number(int num) {
    // A lambda function to return the input num as a vector of its digits
    auto to_vec = [](int num, std::vector<int>& digits) {
      // This will populate the vector 'digits' in reverse order.
      while ( num ) {
        digits.push_back(num % 10);
        num /= 10;
      }

      // Reverse to get back the original order.
      std::reverse(digits.begin(), digits.end());
    };

    // Create a vector to store the digits of the array
    std::vector<int> digits;
    to_vec(num, digits);

    for ( int& digit : digits ) {
      if ( digit == 6 ) {
        // Convert the earliest possible 6 to a 9 and break out.
        digit = 9;
        break;
      }
    }

    // Convert the vector of digits back to a number.
    auto func = [](int acc, int val){ return 10 * acc + val; };
    // Use std::accumulate (instead of std::reduce) to guarantee that each digit
    // in digits in operated on sequentially.
    return std::accumulate(digits.begin(), digits.end(), 0, func);
  }

  /**
   * @brief 1710. Maximum Units on a Truck (Easy)
   * https://leetcode.com/problems/maximum-units-on-a-truck/
   * 
   * Determine the maximum number of units that can fit onto a truck of size
   * 'truck_size'. Each element of box_types is a 2D vector that contains:
   * 
   * 1. The number of boxes of that type.
   * 2. The number of units per box that that box type holds.
   * 
   * @tparam T 
   * @param box_types A 2D vector whose elements are described above.
   * @param truck_size The total number of boxes that the truck can carry.
   * @return size_t The maximum number of units that the truck can carry.
   */
  template<typename T>
  size_t max_units(
    const std::vector<std::vector<T>>& box_types,
    int truck_size)
  {
    // Create a max-heap to store the box info. The default sorting of the queue
    // will use the first value in the pair which is the number of units per box
    // for that box type.
    std::priority_queue<std::pair<T, T>> max_heap;
    for ( const std::vector<T>& info : box_types ) {
      max_heap.push(std::make_pair(info[1], info[0]));
    }

    // Create an alias that's more easily understood.
    int& boxes_remaining = truck_size;

    // Determine the number of units that will fit on the truck.
    size_t total_units{0};
    while( boxes_remaining > 0 && !max_heap.empty() ) {
      // Unpack the current box info
      const auto& [units_per_box, n_boxes] = max_heap.top();

      // Compute the number of boxes to add to the truck.
      T boxes_added = std::min(n_boxes, boxes_remaining);

      // Update the total units on the truck and the number of boxes left to be
      // added.
      total_units += boxes_added * units_per_box;
      boxes_remaining -= boxes_added;

      // Remove this box type - as many boxes of this type as possible have been
      // placed on the truck.
      max_heap.pop();
    }

    return total_units;
  }

  /**
   * @brief 1196. How Many Apples Can You Put in the Basket (Easy)
   * https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/
   * 
   * You have some apples and a basket that can carry up to 5000 units of
   * weight.
   * 
   * Given an integer array weight where weight[i] is the weight of the ith
   * apple, return the maximum number of apples you can put in the basket.
   * 
   * @tparam T 
   * @param weight The input vector of apple weights.
   * @return size_t The maximum number of apples that we can put in the basket.
   */
  template<typename T>
  size_t max_apples(const std::vector<T>& weight) {
    // Create a min heap to store the apple weights
    std::priority_queue<T, std::vector<T>, std::greater<T>> min_heap(
      weight.cbegin(), weight.cend());

    T weight_remaining{5000};
    T total_apples{0};
    while ( weight_remaining > 0 && !min_heap.empty() ) {
      weight_remaining -= min_heap.top();
      total_apples++;
      min_heap.pop();
    }

    // If the last apple added exceeded the weight limit, reduce the apple
    // count by one.
    if ( weight_remaining < 0 ) {
      total_apples--;
    }

    return total_apples;
  }

  /**
   * @brief 1338. Reduce Array Size to The Half (Medium)
   * https://leetcode.com/problems/reduce-array-size-to-the-half/
   * 
   * You are given an integer array nums. You can choose a set of integers and
   * remove all the occurrences of these integers in the array.
   * 
   * Return the minimum size of the set such that at least half of the integers of
   * the array are removed.
   * 
   * @tparam T 
   * @param nums Theh input vector of integer values.
   * @return size_t The minimum size of the set.
   */
  template<typename T>
  size_t min_set_size(const std::vector<T>& nums) {
    // Create a hash table to store the frequency of each value in nums.
    std::unordered_map<T, uint32_t> hist;
    for (const T& num : nums ) {
      hist[num]++;
    }

    // Next create a max-heap sorted by the occurence of each value.
    // TODO: Don't actually need to store both the number and its frequency,
    // just storing the frequency is sufficient to solve the problem.
    using Pair = std::pair<uint32_t, T>;
    std::priority_queue<Pair, std::vector<Pair>> max_heap;
    for ( const auto& [num, freq] : hist ) {
      max_heap.push(std::make_pair(freq, num));
    }

    uint32_t removed_set_size{0};
    size_t reduced_size = nums.size();
    while ( reduced_size > nums.size() / 2 ) {
      const auto& [freq, num] = max_heap.top();
      LOG("Removing " << freq << " instances of " << num);
      reduced_size -= freq;
      removed_set_size++;
      max_heap.pop();
    }

    return removed_set_size;
  }

  /**
   * @brief 1338. Reduce Array Size to The Half (Medium)
   * https://leetcode.com/problems/reduce-array-size-to-the-half/
   * 
   * This was an attempt to solve the problem above using an ordered associative
   * container (std::map). This approach will NOT work because std::map cannot
   * have two items that share the same key. And in this problem, the key is the
   * frequency of occurence of a particular value in nums, and so it's
   * expected that multiple numbers will have the same frequency.
   * 
   * The solution above is correct because std::priority_queue allows for
   * elements to compare "equal" to one another, and so we can store multiple
   * occurences of the same frequency.
   * 
   * @tparam T 
   * @param nums Theh input vector of integer values.
   * @return size_t The minimum size of the set.
   */
  template<typename T>
  size_t min_set_size_2(const std::vector<T>& nums) {
    // Create a hash table to store a histogram of each value in nums.
    std::unordered_map<T, uint32_t> hist;
    for (const T& num : nums ) {
      hist[num]++;
    }

    // Flip the map to be sorted by values (doesn't work with std::greater).
    // std::multimap<uint32_t, T> flipped_hist = dsa::utils::flip_map(hist);

    // Manually flip the keys and values.
    // NOTE: This WON'T work because an (ordered) map cannot have multiple items
    // that share the same key.
    std::map<uint32_t, T, std::greater<uint32_t>> flipped_hist;
    for ( const auto& [num, freq] : hist ) {
      flipped_hist[freq] = num;
    }

    LOG("min_set_size_2");
    uint32_t removed_set_size{0};
    size_t reduced_size = nums.size();
    for ( const auto& [freq, num] : flipped_hist ) {
      LOG("Removing " << freq << " instances of " << num);
      reduced_size -= freq;
      removed_set_size++;
      if ( reduced_size <= nums.size() / 2) {
        break;
      }
    }

    return removed_set_size;
  }
}