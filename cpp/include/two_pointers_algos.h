#pragma once
/**
 * @file two_pointers_algos.h
 * @author Carl Stahoviak
 * @brief The back-end algorithm implementation of various flavors of the
 *  "two pointers" algorithm
 * @date 2024-05-06
 */

#include "utils.h"

#include <iterator>
#include <string>
#include <vector>

namespace algorithms::_two_pointers {
  /**
   * @brief Solves the two-sum algorithm for a sorted container of unique values.
   * 
   * @param left An iterator pointing to the first element of the contianer.
   * @param right An iterator pointing to the last element of the container.
   * @param target The target sum.
   * @return True if there is at least one pair of values that sums to the the
   * target sum; false otherwise.
   */
  template <class Iter, class T = typename std::iterator_traits<Iter>::value_type>
  bool _two_sum(Iter left, Iter right, T target) {
    while (left < right) {
      // Only LOG if compiled with DEBUG_INFO=ON
      LOG("left: " << *left << ", right: " << *right);
      T sum = *left + *right;
      if (sum > target)
        right--;
      else if (sum < target)
        left++;
      else
        return true;
    }
    return false;
  }

  /**
   * @brief Given two sorted arrays, return a new array that combines both arrays
   * and is also sorted.
   * 
   * @tparam Iter 
   * @tparam std::iterator_traits<Iter>::value_type 
   * @param begin1 Iterator to the start of the first container of sorted values.
   * @param end1 Iterator to the end of the first container of sorted values.
   * @param begin2 Iterator to the start of the second container of sorted values.
   * @param end2 Iterator to the end of the second container of sorted values.
   * @return std::vector<T> The combined (and sorted) vector
   */
  template <class Iter, class T = typename std::iterator_traits<Iter>::value_type>
  std::vector<T> _combine_sorted(Iter begin1, Iter end1, Iter begin2, Iter end2) {
    // using T = typename std::iterator_traits<Iter>::value_type;
    std::vector<T> combined;

    while (begin1 != end1 && begin2 != end2) {
      if ( *begin1 < *begin2 ) {
        combined.push_back(*begin1);
        begin1++;
      }
      else {
        combined.push_back(*begin2);
        begin2++;
      }
    }

    while (begin1 != end1 ) {
      // Add remaining values from array1
      combined.push_back(*begin1);
      begin1++;
    }

    while (begin2 != end2 ) {
      // Add remaining values from array2
      combined.push_back(*begin2);
      begin2++;
    }

    return combined;
  }

  /**
   * @brief Given two strings s and t, return true if s is a subsequence of t,
   * false otherwise.
   * 
   * A subsequence of a string is a sequence of characters that can be obtained
   * by deleting some (or none) of the characters from the original string,
   * while maintaining the relative order of the remaining characters. For
   * example, "ace" is a subsequence of "abcde" while "aec" is not.
   * 
   * @param s The subsequence to find in 't'.
   * @param t The string to search for 's' in.
   * @return True if the subsequence 's' is in 't', False otherwise.
   */
  bool _is_subsequence(std::string s, std::string t) {
    size_t s_idx = 0;
    size_t t_idx = 0;

    if (t.size() < s.size()) {
      return false;
    }

    while (s_idx < s.size() && t_idx < t.size()) {
      LOG("t[" << t_idx << "]: " << t[t_idx] << ", s[" << s_idx << "]: " << s[s_idx])
      if (s[s_idx] == t[t_idx]) {
        s_idx++;
      }
      t_idx++;
    }
        
    return s_idx == s.size();
  }
} // end namespace algorithms::_two_pointers
