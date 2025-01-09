/**
 * @file hashing.h
 * @author Carl Stahoviak
 * @brief Hashing algorithms.
 * @version 0.1
 * @date 2025-01-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace dsa::data_structures::hash_maps
{
  /**
   * @brief A pangram is a sentence where every letter of the English alphabet
   * appears at least once.
   * 
   * @param sentence 
   * @return true if the sentence is a pangram.
   * @return false if the sentence is not a pangram.
   */
  bool is_pangram(std::string_view sentence) {
    // Create an unordered set from the input sentence
    std::unordered_set<char> char_set(sentence.begin(), sentence.end());

    // If the length of the string is 26, then the sentence is a pangram.
    return char_set.size() == 26;
  }

  /**
   * @brief Given an array nums containing 'n' distinct numbers in the range 
   * [0, n], return the only number in the range that is missing from the array.
   * 
   * @param nums The input integer array. All numbers in 'nums' are guaranteed
   * to be unique. 
   * @return int The missing integer in 'nums' in the range [0, n].
   */
  int missing_number(const std::vector<int>& nums) {
    // Create an unordered set from the input vector 
    std::unordered_set<int> set(nums.begin(), nums.end());

    // Find the missing number
    for ( int idx = 0; idx < nums.size(); idx++ ) {
      if ( set.find(idx) == set.end() ) {
        return idx;
      }
    }
    return -1;
  }

  /**
   * @brief Given an array nums containing 'n' distinct numbers in the range 
   * [0, n], return the only number in the range that is missing from the array.
   * 
   * This solution uses an improved method that takes advantage of the summation
   * 1 + 2 + 3 + ... + n
   * 
   * @param nums The input integer array. All numbers in 'nums' are guaranteed
   * to be unique. 
   * @return int The missing integer in 'nums' in the range [0, n].
   */
  int missing_number_improved(const std::vector<int>& nums) {
    // The missing value will be the sum of the series from 0 to n minus the
    // sum of the input vector.
    return (nums.size() * (nums.size() + 1)) / 2 -
      std::accumulate(nums.begin(), nums.end(), 0);;
  }

  /**
   * @brief Given an integer array 'nums' and an integer 'k', find the number of
   * subarrays whose sum is equal to 'k'.
   * 
   * TODO: Finish this function.
   * 
   * @tparam T 
   * @param nums 
   * @param k 
   * @return size_t 
   */
  template<typename T>
  size_t n_subarray_sums(const std::vector<T>& nums, T k) {
    return 0;
  }

  /**
   * @brief 
   * 
   * @param matches 
   * @return std::vector<std::vector<int>> 
   */
  std::vector<std::vector<int>> n_losses(
    const std::vector<std::vector<int>>& matches)
  {
    // Create a sets of winners and losers, and a loss count per player
    std::set<int> winners;
    std::set<int> losers;
    std::unordered_map<int, int> losses;
    for ( const std::vector<int>& match : matches ) {
      // Update the winners and losers sets
      winners.insert(match.at(0));
      losers.insert(match.at(1));
      
      // Take advatange of the fact that integer types in maps default to 0.
      losses[match.at(1)]++;
    }
    
    // Create answer consisting of 2 vectors.
    std::vector<std::vector<int>> answer(2);
    
    // Use set_difference to find all players never lost a match
    std::set_difference(
      winners.begin(), winners.end(),
      losers.begin(), losers.end(),
      // std::inserter(answer.at(0), answer.at(0).end())
      std::back_inserter(answer.at(0))
    );
    
    // Find all players that have lost exactly once.
    for ( const auto& [player, loss_count] : losses ) {
      if ( loss_count == 1 ) {
        answer.at(1).push_back(player);
      }
    }

    // The values in the two lists should be returned in increasing order.
    std::sort(answer.at(0).begin(), answer.at(0).end());
    std::sort(answer.at(1).begin(), answer.at(1).end());
    
    return answer;
  }

  /**
   * @brief Given an integer array nums, return the largest integer that only
   * occurs once. If no integer occurs once, return -1.
   * 
   * @tparam T 
   * @param nums 
   * @return T 
   */
  template<typename T>
  T largest_unique_number(const std::vector<T>& nums) {
    // Create a map to count the number of occurences of each value.
    std::map<int, size_t, std::greater<int>> counts;
    for ( const int& num : nums ) {
      counts[num]++;
    }
    
    // Since we're already sorted in decreasing order, return the first value
    // whose count is 1.
    for ( const auto& [num, count] : counts ) {
      if ( count == 1 ) {
        return num;
      }
    }
    
    return -1;
  }
}