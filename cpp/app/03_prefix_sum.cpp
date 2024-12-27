/**
 * @file 03_prefix_sum.cpp
 * @author Carl Stahoviak
 * @brief 
 * @date 2024-05-24
 * 
 */

#include "dsa/algorithms/prefix_sum.h"
#include "dsa/utils.h"

using namespace dsa::algorithms;
namespace utils = dsa::utils;

int main() {
  // Example 1: Simple prefix sum problem.
  {
    std::cout << "Example 1: Simple prefix sum problem:" << std::endl;

    std::vector<int> nums = { 1, 6, 3, 2, 7, 2 };
    std::vector<std::vector<int>> queries = { {0, 3}, {2, 5}, {2, 4} };
    int limit = 13;
    std::vector<bool> result = prefix_sum::query_sum(nums, queries, limit);
    // In C++23, we could use zip(), but not in C++17
    // for (const auto& [r, query] : std::ranges::views::zip(result, queries)) {
    //   std::cout << query << ": " << dsa::utils::bool_to_string(r) << std::endl;
    // }
    for (size_t idx = 0; idx < queries.size(); idx++) {
      std::cout << queries[idx] << ": " << 
        utils::bool_to_string(result[idx]) << std::endl;
    }
  }

  // Example 2: Number of ways to split an array
  // https://leetcode.com/problems/number-of-ways-to-split-array/description/
  {
    std::cout << "\nExample 2: N valid bisections:" << std::endl;

    std::vector<int> nums = { 10, 4, -8, 7 };
    auto valid_idxs = prefix_sum::bisect_n_ways(nums);

    std::cout << "There are " << valid_idxs.size() <<
      " valid bisections of " << nums << " such that the left bisection " <<
      "has a sum greater than or equal to the right bisection." << std::endl;

    // Use structured bindings to unpack the contents
    for (auto& [lsplice, rsplice] : valid_idxs ) {
      std::cout << lsplice << ", " << rsplice << std::endl;
    }
  }
}