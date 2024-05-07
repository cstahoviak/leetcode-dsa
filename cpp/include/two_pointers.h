#pragma once
/**
 * @file two_pointers.h
 * @author Carl Stahoviak
 * @brief Various implementations of the two-pointers algorithm.
 * @date 2024-05-03 
 */

#include "utils.h"

#include <algorithm>
#include <array>
// Include to get 'size_t'
#include <cstddef>
#include <iostream>
#include <vector>

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

template <typename T, size_t N>
bool two_sum(std::array<T, N> arr, T target) {
  return _two_sum(arr.begin(), arr.end() - 1, target);
}

template <typename T>
bool two_sum(std::vector<T> vec, T target) {
  return _two_sum(vec.begin(), vec.end() - 1, target);
}

/**
 * @brief Given two sorted arrays, return a new array that combines both arrays
 * and is also sorted.
 * 
 * @tparam Iter 
 * @tparam std::iterator_traits<Iter>::value_type 
 * @tparam N 
 * @param begin1 
 * @param end1 
 * @param begin2 
 * @param end2 
 * @param out_arr 
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

template <typename T, size_t N, size_t M>
std::array<T, N+M> combine_sorted(std::array<T, N>& arr1, std::array<T, M>& arr2) {
  auto temp =
    _combine_sorted(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());

  std::array<T, N+M> combined;
  std::move(temp.begin(), temp.end(), combined.begin());
  return combined;
}

template <typename T>
std::vector<T> combine_sorted(std::vector<T>& vec1, std::vector<T>& vec2) {
  return _combine_sorted(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
}