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

int main() {
  std::cout << "The Two-Sum algorithm:\n";

  // Define the target sum
  int target = 4;

  // Solve the two-sum problem with a static array
  std::array<int, 10> values = { 1, 6, 10, 3, 7, 8, 0, 12, 2, 5 };
  std::sort(values.begin(), values.end());
  bool result1 = check_if_target_sum(values, target);
  std::cout << values << ": " << bool_to_string(result1) << std::endl;

  // Solve the two-sum problem with a vector (dynamic array)
  std::vector<int> vec(values.begin(), values.end());
  bool result2 = check_if_target_sum(vec, target);
  std::cout << vec << ": " << bool_to_string(result2) << std::endl;

}