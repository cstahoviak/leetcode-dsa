/**
 * @file two_pointers.cpp
 * @author Carl Stahoviak
 * @brief Examples that implement some flavor of the "Two Pointers" algorithm.
 * @date 2024-05-02
 * 
 * TODO: Turn this app into unit tests:
 *    - Unit tests for the cpp implementations on their own
 *    - Unit tests validating the cpp code bindings against python
 *      implementations of the same algortihms.
 */

#include "dsa/algorithms/two_pointers.h"
#include "dsa/utils.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
void show_result(std::array<T, N> arr, T target, bool result) {
  std::cout << "values=" << arr << ", target=" << target << ": " << 
    dsa::utils::bool_to_string(result) << std::endl;
}

template <typename T>
void show_result(std::vector<T> vec, T target, bool result) {
  std::cout << "values=" << vec << ", target=" << target << ": " <<
    dsa::utils::bool_to_string(result) << std::endl;
}

int main() {
  // The two-sum problem
  {
    std::cout << "The Two-Sum algorithm:\n";
    // Define the target sum
    int target = 23;

    // Solve the two-sum problem with a static array
    std::array<int, 10> values = { 1, 6, 10, 3, 7, 8, 0, 12, 2, 5 };
    std::sort(values.begin(), values.end());
    auto result1 = dsa::algorithms::two_pointers::two_sum(values, target);
    show_result(values, target, result1);
    // show_result(values, target, two_sum(values, target));

    // Solve the two-sum problem with a vector (dynamic array)
    std::vector<int> vec(values.begin(), values.end());
    auto result2 = dsa::algorithms::two_pointers::two_sum(values, target);
    show_result(values, target, result2);
    // show_result(vec, target, two_sum(vec, target));
  }

  // Combine two sorted arrays via the two-pointers algorithm
  {
    std::cout << "\nCombine two sorted arrays using two-pointers:\n";

    std::cout << "Solve using static arrays:\n";
    std::array<int, 5> arr1 = { 4, 0, 6, 1, 2 };
    std::array<int, 6> arr2 = { 3, 5, 7, 9, 8, 0};
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    auto result1 = dsa::algorithms::two_pointers::combine_sorted(arr1, arr2);
    std::cout << arr1 << " + " << arr2 << " = " << result1 << std::endl;

    std::cout << "Solve using vectors (dynamic arrays):\n";
    std::vector<int> vec1(arr1.begin(), arr1.end());
    std::vector<int> vec2(arr2.begin(), arr2.end());
    auto result2 = dsa::algorithms::two_pointers::combine_sorted(vec1, vec2);
    std::cout << vec1 << " + " << vec2 << " = " << result2 << std::endl;
  }

  // Find a subsequence in a larger string using two-pointers
  {
    std::cout << "\nFind a subsequence in a larger string using two-pointers\n";
    std::string s = "ace";
    std::string t = "aabcdfgahcie";
    bool result = dsa::algorithms::two_pointers::is_subsequence(s, t);
    std::cout << "'" << s << "' in '" << t << "': " << 
      dsa::utils::bool_to_string(result) << std::endl; 
  }

  // Example 1: Reverse a string
  {
    std::cout << "\nExample 1: Reverse a string:\n";
    std::string a = "Stahoviak";
    std::cout << a << " reversed: ";
    dsa::algorithms::two_pointers::reverse(a);
    std::cout << a << std::endl;
  }

  // Example 2: Square and sort a non-decreasing vector.
  {
    std::cout << "\nExample 2: Square and sort a non-decreasing vector:\n";

    std::cout << "Solve using static arrays:\n";
    std::array<int, 6> arr = { -7, -3, 2, 3, 11, 12 };
    std::array<int, 6> result1 = 
      dsa::algorithms::two_pointers::sorted_squares(arr);
    std::cout << arr << "^2 = " << result1 << std::endl;

    std::cout << "Solve using vectors (dynamic arrays):\n";
    std::vector<int> vec(arr.begin(), arr.end());
    std::vector<int> result2 =
      dsa::algorithms::two_pointers::sorted_squares(vec);
    std::cout << vec << "^2 = " << result2 << std::endl;
  }
}