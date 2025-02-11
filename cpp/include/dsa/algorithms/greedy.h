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
   * @brief You are given a positive integer num consisting only of digits 6 and 9.
   * 
   * Return the maximum number you can get by changing at most one digit
   * (6 becomes 9, and 9 becomes 6).
   * 
   * @param num The input number.
   * @return int The output value with at most one changed digit.
   */
  int maximum_69_number(int num) {
    // A simple lambda function to return the input num as a vector of its digits
    auto to_vec = [](int num, std::vector<int>& digits) {
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
    auto func = [](int acc, int val){return 10 * acc + val; };
    return std::accumulate(digits.begin(), digits.end(), 0, func);
  }

  /**
   * @brief 1710. Maximum Units on a Truck
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

    // Determine the number of units that will fit on the truck
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

  template<typename T>
  size_t max_apples(const std::vector<T>& weight) {
    return 0;
  }

  template<typename T>
  size_t min_set_size(const std::vector<T>& vec) {
    return 0;
  }
}