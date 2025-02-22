#pragma once
/**
 * @file hashing.h
 * @author Carl Stahoviak
 * @brief Problems associated with the hash map data structure.
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
#include <string>         // std::string::npos
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace dsa::data_structures::hash_maps
{
  /**
   * @brief 1832. Check if the Sentence is a Pangram (Easy)
   * https://leetcode.com/problems/check-if-the-sentence-is-pangram/
   * 
   * A pangram is a sentence where every letter of the English alphabet
   * appears at least once.
   * 
   * @param sentence A sentence containing only lowercase English letters.
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
   * @brief 268. Missing Number (Easy)
   * https://leetcode.com/problems/missing-number/
   * 
   * Given an array nums containing 'n' distinct numbers in the range 
   * [0, n], return the only number in the range that is missing from the array.
   * 
   * @param nums The input integer array. All numbers in 'nums' are guaranteed
   * to be unique. 
   * @return int The missing integer in 'nums' in the range [0, n].
   */
  int missing_number(const std::vector<int>& nums) {
    // Create an unordered set from the input vector 
    std::unordered_set<int> set(nums.cbegin(), nums.cend());

    // Find the missing number
    for ( int idx = 0; idx < nums.size(); idx++ ) {
      if ( set.find(idx) == set.end() ) {
        return idx;
      }
    }
    return -1;
  }

  /**
   * @brief 268. Missing Number (Easy)
   * https://leetcode.com/problems/missing-number/
   * 
   * Given an array nums containing 'n' distinct numbers in the range 
   * [0, n], return the only number in the range that is missing from the array.
   * 
   * This solution uses an improved method that takes advantage of knowing the
   * value of the summation: 1 + 2 + 3 + ... + n
   * 
   * @param nums The input integer array. All numbers in 'nums' are guaranteed
   * to be unique. 
   * @return int The missing integer in 'nums' in the range [0, n].
   */
  int missing_number_improved(const std::vector<int>& nums) {
    // The missing value will be the sum of the series from 0 to n minus the
    // sum of the input vector.
    return (nums.size() * (nums.size() + 1)) / 2 -
      std::reduce(nums.cbegin(), nums.cend(), 0);;
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
   * @brief 2225. Find Players with Zero or One Losses (Medium)
   * https://leetcode.com/problems/find-players-with-zero-or-one-losses/
   * 
   * You are given an integer array matches where matches[i] = 
   * [winner_i, loser_i] indicates that the player winner_i defeated player
   * loser_i in a match. 
   * 
   * Return a list answer of size 2 where:
   * - answer[0] is a list of all players that have not lost any matches.
   * - answer[1] is a list of all players that have lost exactly one match.
   * 
   * The values in the two lists should be returned in increasing order, and
   * you should only consider players that have played at least one match.
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
   * @brief 1133. Largest Unique Number (Easy)
   * https://leetcode.com/problems/largest-unique-number/
   * 
   * Given an integer array nums, return the largest integer that only
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

  /**
   * @brief 383. Ransom Note (Easy)
   * https://leetcode.com/problems/ransom-note/
   * Given two strings 'ransom_note' and 'magazine', return true if 
   * 'ransom_note' can be constructed by using the letters from magazine and
   * false otherwise.
   * 
   * Each letter in magazine can only be used once in ransomNote.
   * 
   * @param ransom_note 
   * @param magazine 
   * @return true 
   * @return false 
   */
  inline bool ransom_note(
    std::string_view ransom_note,
    std::string_view magazine)
  {
    // Create a map to store character counts for the magazine.
    std::unordered_map<char, int> character_counts;
    for ( const char& character : magazine ) {
      character_counts[character]++;
    }
    
    // Iterate over the ransom note until we have exhausted a particular character.
    for ( const char& character : ransom_note ) {
      // if ( !character_counts.contains(character) ) {
      //     // The required ransom note character is not available in the magazine.
      //     return false;
      // }
      
      // Decrement the character count by one. Note that if a character in the
      // ransom note doesn't exist in the character_counts map, the line below will
      // create it with a default value of zero and then decrement it to -1, thus
      // removing the need for the conditional above.
      character_counts[character]--;
      if ( character_counts[character] < 0 ) {
        return false;
      }
    }
    
    return true;
  }

  /**
   * @brief 771. Jewels and Stones (Easy)
   * https://leetcode.com/problems/jewels-and-stones/
   * 
   * You're given strings 'jewels' representing the types of stones that are
   * jewels, and ` representing the stones you have. Each character in 'stones'
   * is a type of stone you have. You want to know how many of the stones you
   * have are also jewels.
   * 
   * Letters are case sensitive, so "a" is considered a different type of stone
   * from "A".
   * 
   * @param jewels 
   * @param stones 
   * @return int 
   */
  int num_jewels(std::string_view jewels, std::string_view stones) {
    // Count the number of each type of stone.
    std::unordered_map<char, size_t> stone_counts;
    for ( const char& type : stones ) {
      stone_counts[type]++;
    }
    
    int result{0};
    for (const auto& [type, count] : stone_counts ) {
      // C++23: use contains()
      // if ( jewels.contains(type) ) {
      //   result += stone_counts[type];
      // }

      // C++17: use find()
      if ( jewels.find(type) != std::string::npos ) {
        result += stone_counts[type];
      }
    }
    
    return result;
  }
}