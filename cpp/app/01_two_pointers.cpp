/**
 * @file two_pointers.cpp
 * @author Carl Stahoviak
 * @brief Examples that implement some flavor of the "Two Pointers" algorithm.
 * @date 2024-05-02
 */

#include "two_pointers.h"
#include "utils.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
void show_result(std::array<T, N> arr, T target) {
  bool result = check_if_target_sum(arr, target);
  std::cout << "values=" << arr << ", target=" << target << ": " << 
    bool_to_string(result) << std::endl;
}

template <typename T>
void show_result(std::vector<T> vec, T target) {
  bool result = check_if_target_sum(vec, target);
  std::cout << "values=" << vec << ", target=" << target << ": " <<
    bool_to_string(result) << std::endl;
}

int main() {
  std::cout << "The Two-Sum algorithm:\n";

  // Define the target sum
  int target = 23;

  // Solve the two-sum problem with a static array
  std::array<int, 10> values = { 1, 6, 10, 3, 7, 8, 0, 12, 2, 5 };
  std::sort(values.begin(), values.end());
  show_result(values, target);

  // Solve the two-sum problem with a vector (dynamic array)
  std::vector<int> vec(values.begin(), values.end());
  show_result(vec, target);

}