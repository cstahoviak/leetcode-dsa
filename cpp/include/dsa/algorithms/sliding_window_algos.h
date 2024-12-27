#pragma once
/**
 * @file sliding_window_algos.h
 * @author Carl stahoviak
 * @brief The back-end algorithm implementation of various flavors of the
 *  "sliding window" algorithm. None of these should be called directly, they
 *  should be called via functions in the algorithms::slidind_window namespace.
 * @date 2024-05-22
 * 
 */

#include <iterator>

namespace dsa::algorithms::_sliding_window
{
  /**
   * @brief Solves the various flavors of the "maximum cosecutive ones" problem.
   * 
   * @tparam Iter 
   * @tparam std::iterator_traits<Iter>::value_type 
   * @param begin 
   * @param end 
   * @param zero_val 
   * @param k 
   * @return size_t 
   */
  template <class Iter, class T = typename std::iterator_traits<Iter>::value_type>
  size_t _max_consecutive_ones(Iter begin, Iter end, T zero_val, size_t k) {
    // Start both pointers at the beginning of the array
    Iter left = begin;
    Iter right = begin;

    size_t num_zeros = 0;
    size_t max_length = 0;

    while (right < end) {
      if (*right == zero_val ) {
        num_zeros++;
      }

      while ( num_zeros > k ) {
        if ( *left == zero_val ) {
          num_zeros -= 1;
        } 
        left++;
      }
      // The size of the window will always be (right - left + 1)
      max_length = std::max(max_length, (right - left) + (size_t)1);
      right++;
    }
    return max_length;
  }
} // end namespace dsa::algorithms::_sliding_window
