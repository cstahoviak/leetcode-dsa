#pragma once
/**
 * @file two_pointers_algos.h
 * @author Carl Stahoviak
 * @brief The back-end algorithm implementation of various flavors of the
 *  "two pointers" algorithm. None of these should be called directly, they
 *  should be called via function in the algorithms::two_pointers namespace.
 * @date 2024-05-06
 */

#include "dsa/utils.h"

#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>
#include <vector>

namespace dsa::algorithms::_two_pointers {

  /**
   * @brief Solves the two-sum algorithm for a sorted container of unique
   * values.
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
   * @brief Given two sorted arrays, return a new array that combines both
   * arrays and is also sorted.
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
  bool _is_subsequence(std::string& s, std::string& t) {
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

  /**
   * @brief Write a function that reverses a string. The input string is given
   * as an array of characters s.
   * 
   * You must do this by modifying the input array in-place with O(1) extra
   * memory.
   * 
   */
  void _reverse(std::string& s) {
    std::string::iterator left = s.begin();
    std::string::iterator right = s.end() - 1;

    while (left < right) {
      LOG("swapping '" << *left << "' and '" << *right << "'");
      auto temp = *left;
      *left = *right;
      *right = temp;

      left++;
      right--;
    }
  }

  /**
   * @brief Given an integer array nums sorted in non-decreasing order, return
   * an array of the squares of each number sorted in non-decreasing order.
   * 
   * TODO: Squaring each element and sorting the new array is very trivial, can
   * we find an O(n) solution using a different approach?
   * 
   * @tparam T 
   * @param values 
   * @return std::vector<T> 
   */
  template<typename T>
  std::vector<T> _sorted_squares_slow(std::vector<T>& values) {
    std::vector<T> squared(values.size());

    // The following loop costs O(n)
    size_t idx = 0;
    for (auto& val : values) {
      squared[idx] = pow(val, 2);
      idx++;
    }

    // What is the time complexity of std::sort?
    std::sort(squared.begin(), squared.end());
    return squared;
  }

  /**
   * @brief Uses a version of the two-pointers algorithm to improve the runtime
   * speed of the "sorted squares" algortihm to O(n).
   * 
   * @tparam T 
   * @param values 
   * @return std::vector<T> 
   */
  template <class Iter, class T = typename std::iterator_traits<Iter>::value_type>
  std::vector<T> _sorted_squares(Iter left, Iter right, size_t size) {
    std::vector<T> result(size);
    size_t idx = size - 1;

    while (left <= right) {
      if (std::abs(*right) > std::abs(*left)) {
        result[idx] = pow(*right, 2);
        right--;
      }
      else {
        result[idx] = pow(*left, 2);
        left++;
      }
      idx--;
    }

    return result;
  }

} // end namespace dsa::algorithms::_two_pointers
