#pragma once
/**
 * @brief Solves the "Two Sum" problem, i.e. given a sorted array of unique
 *    integers and a target integer, return true if there exists a pair of
 *    numbers that sum to the target value.
 * 
 * @tparam Iter 
 * @param begin A pointer to the beginning of a sorted iterable container.
 * @param end A pointer to the beginning of a sorted iterable container.
 * @param target The desired sum.
 * @return true if the iterable contains a pair of numbers that sum to the 
 *    target value. False otherwise.
 */

#include <array>
// Include to get 'size_t'
#include <cstddef>
#include <vector>

template <class Iter, class T = typename std::iterator_traits<Iter>::value_type>
bool _check_if_target_sum(Iter begin, Iter end, T target) {
  while (begin < end) {
    T sum = *begin + *end;
    if (sum > target)
      end--;
    else if (sum < target)
      begin++;
    else
      return true;
  }
  return false;
}

template <typename T, size_t N>
bool check_if_target_sum(std::array<T, N> arr, T target) {
  return _check_if_target_sum(arr.begin(), arr.end(), target);
}

template <typename T>
bool check_if_target_sum(std::vector<T> vec, T target) {
  return _check_if_target_sum(vec.begin(), vec.end(), target);
}