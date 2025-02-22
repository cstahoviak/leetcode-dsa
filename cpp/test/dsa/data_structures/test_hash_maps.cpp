/**
 * @file test_hashing.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for the hash_maps module.
 * @version 0.1
 * @date 2025-01-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/data_structures/hash_maps.h"

#include <gtest/gtest.h>

using namespace dsa::data_structures;

TEST(TestHashingAlgorithms, TestIsPangram) {
  const std::string input1{"thequickbrownfoxjumpsoverthelazydog"};
  const std::string input2{"leetcode"};

  EXPECT_TRUE(hash_maps::is_pangram(input1));
  EXPECT_FALSE(hash_maps::is_pangram(input2));
}

TEST(TestHashingAlgorithms, TestMissingNumber) {
  const std::vector<int> nums {9,6,4,2,3,5,7,0,1};
  EXPECT_EQ(hash_maps::missing_number(nums), 8);
  EXPECT_EQ(hash_maps::missing_number_improved(nums), 8);
}

TEST(TestHashingAlgorithms, TestNLosses) {
  std::vector<std::vector<int>> matches = {
    {1,3}, {2,3}, {3,6}, {5,6}, {5,7}, {4,5}, {4,8}, {4,9}, {10,4}, {10,9}
  };

  const std::vector<int> wins_only { 1, 2, 10 };
  const std::vector<int> one_loss { 4, 5, 7, 8};
  const std::vector<std::vector<int>> expected { wins_only, one_loss };

  const auto result = hash_maps::n_losses(matches);
  EXPECT_EQ(result, expected);
}

TEST(TestHashingAlgorithms, TestLargestUniqueNumber) {
  std::vector<int> input1 = { 5,7,3,9,4,9,8,3,1 };
  EXPECT_EQ(hash_maps::largest_unique_number(input1), 8);

  std::vector<int> input2 = { 9,9,8,8 };
  EXPECT_EQ(hash_maps::largest_unique_number(input2), -1);
}

TEST(TestHashingAlgorithms, TestRansomNote) {
  // Define the test data
  const std::pair<std::string, std::string> data1 = { "a", "b"};
  const std::pair<std::string, std::string> data2 = { "aa", "ab"};
  const std::pair<std::string, std::string> data3 = { "aa", "aab"};

  EXPECT_FALSE(hash_maps::ransom_note(data1.first, data1.second));
  EXPECT_FALSE(hash_maps::ransom_note(data2.first, data2.second));
  EXPECT_TRUE(hash_maps::ransom_note(data3.first, data3.second));
}

TEST(TestHashingAlgorithms, TestNumJewels) {
  // Define the test data
  const std::pair<std::string, std::string> data1 = { "aA", "aAAbbbb"};
  const std::pair<std::string, std::string> data2 = { "z", "ZZ"};

  EXPECT_EQ(hash_maps::num_jewels(data1.first, data1.second), 3);
  EXPECT_EQ(hash_maps::num_jewels(data2.first, data2.second), 0);
}

