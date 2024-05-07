#pragma once
/**
 * @file two_pointers.h
 * @author Carl Stahoviak
 * @brief The templated front-end implementation of the two-pointers algortihms.
 * @date 2024-05-03 
 */

#include "two_pointers_algos.h"

#include <array>
// Include to get 'size_t'
#include <cstddef>

namespace algorithms::two_pointers {

  // Short-hand for the back-end two-pointers namespace
  namespace tp = algorithms::_two_pointers;

  template <typename T, size_t N>
  bool two_sum(std::array<T, N> arr, T target) {
    return tp::_two_sum(arr.begin(), arr.end() - 1, target);
  }

  template <typename T>
  bool two_sum(std::vector<T> vec, T target) {
    return tp::_two_sum(vec.begin(), vec.end() - 1, target);
  }

  template <typename T, size_t N, size_t M>
  std::array<T, N+M> combine_sorted(std::array<T, N>& arr1, std::array<T, M>& arr2) {
    auto temp =
      tp::_combine_sorted(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());

    std::array<T, N+M> combined;
    std::move(temp.begin(), temp.end(), combined.begin());
    return combined;
  }

  template <typename T>
  std::vector<T> combine_sorted(std::vector<T>& vec1, std::vector<T>& vec2) {
    return tp::_combine_sorted(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
  }

  /**
   * @brief This is simply a pass-through for the 'is_subsequence" algorithm for
   * now.
   * 
   * TODO: Add templatization to support both std::string and char*.
   * 
   * @param s 
   * @param t 
   * @return true 
   * @return false 
   */
  bool is_subsequence(std::string& s, std::string& t) {
    return tp::_is_subsequence(s, t);
  }

}
