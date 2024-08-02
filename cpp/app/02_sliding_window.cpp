/**
 * @file 02_sliding_window.cpp
 * @author Carl Stahoviak
 * @brief Examples that implement some flavor of the "Sliding Window" algorithm.
 * @date 2024-05-21
 * 
 * TODO: Turn this app into unit tests:
 *    - Unit tests for the cpp implementations on their own
 *    - Unit tests validating the cpp code bindings against python
 *      implementations of the same algortihms.
 */

#include "dsa/algorithms/sliding_window.h"
#include "dsa/utils.h"

namespace sw = dsa::algorithms::sliding_window;
namespace utils = dsa::utils;

int main() {
  // Longest subarray
  {
    std::vector<int> v = { 3, 1, 2, 7, 4, 2, 1, 1, 5 };
    int sum = 9;
    auto longest = sw::longest_subarray(v, sum);
    std::cout << "Longest subarray in " << v << " less than " << sum << " is: "
      << longest << std::endl;
  }

  // Flip one zero to create the longest subarray of ones
  {
    std::string s = "11001011";
    auto longest = sw::flip_one(s);
    std::cout << "\nLongest string of 1s in '" << s << 
      "' created by flipping only one zero is " << longest << 
      " characters in length." << std::endl;
  }

  // Find the maximum sum of a fixed-size window
  {
    std::vector<int> nums { 3, -1, 4, 12, -8, 5, 6 };
    int window_size = 4;
    int max_sum = sw::largest_sum(nums, window_size);
    std::cout << "\nThe largest sum in " << nums << " for a window_size of '" 
      << window_size << "' is: " << max_sum << std::endl;
  }

  // Example 1: Maximum Average Subarray
  {
    // std::vector<int> nums = { 1, 12, -5, -6, 50, 3 };
    std::vector<int> nums = { 4, 0, 4, 3, 3 };
    int window_size = 5;
    auto max_avg = sw::max_avg_subarray(nums, window_size);
    std::cout << "\nThe maximum average subarray of size '" << window_size <<
      "' in " << nums << " is: " << max_avg << std::endl;
  }

  // Example 2: Maximum Consecutive Ones
  // This problem is actually the same as the "flip_one" problem above
  {
    std::vector<int> nums = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    int k = 3;
    int longest = sw::max_consecutive_ones(nums, k);
    std::cout << "\nLongest string of 1s in " << nums << 
      " created by flipping at most '" << k << "' zeros is " << longest << 
      " characters in length." << std::endl;
  }
}