#pragma once
/**
 * @file two_pointers.h
 * @author Carl Stahoviak
 * @brief The templated front-end implementation of the two-pointers algortihms
 *  that is intended to be the user-facing inteface of the
 *  algorithms::two_pointers namespace.
 * @date 2024-05-03 
 */

#include "dsa/algorithms/two_pointers_algos.h"
#include "dsa/utils.h"

#include <array>
// Include to get 'size_t'
#include <cstddef>

namespace dsa::algorithms::two_pointers
{
  // Short-hand for the back-end two-pointers namespace
  namespace tp = dsa::algorithms::_two_pointers;

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
    return tp::_combine_sorted(
      vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
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

  /**
   * @brief This is simply a pass-through for the 'reverse" algorithm for now.
   * now.
   * 
   * TODO: Add templatization to support both std::string and char*.
   * 
   * @param s 
   */
  void reverse(std::string& s) {
    tp::_reverse(s);
  }

  template<typename T>
  std::vector<T> sorted_squares(std::vector<T>& values) {
    return tp::_sorted_squares(values.begin(), values.end() - 1, values.size());
  }

  template<typename T, size_t N>
  std::array<T, N> sorted_squares(std::array<T, N>& values) {
    std::vector<T> temp = tp::_sorted_squares(
      values.begin(), values.end() - 1, values.size());
    
    std::array<T, N> result;
    std::move(temp.begin(), temp.end(), result.begin());
    return result;
  }
} // end namespace dsa::algorithms::two_pointers