/**
 * @file test_heaps.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/data_structures/heaps.h"

#include <gtest/gtest.h>

using namespace dsa::data_structures;

TEST(TestHeaps, TestMinStoneSum) {
  // Define the inputs
  const std::vector<int> piles1 = {5, 4, 9};
  const std::vector<int> piles2 = {4, 3, 6, 7};

  EXPECT_EQ(heaps::min_stone_sum(piles1, 2), 12);
  EXPECT_EQ(heaps::min_stone_sum(piles2, 3), 12);
}

TEST(TestHeaps, TestConnectSticks) {
  // Define the inputs
  const std::vector<int> sticks1 = {2, 4, 3};
  const std::vector<int> sticks2 = {1, 8, 3, 5};
  const std::vector<int> sticks3 = {5};

  EXPECT_EQ(heaps::connect_sticks(sticks1), 14);
  EXPECT_EQ(heaps::connect_sticks(sticks2), 30);
  EXPECT_EQ(heaps::connect_sticks(sticks3), 0);
}

TEST(TestHeaps, TestKthLargest) {
  // Define the inputs
  const std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
  const std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  const int k1 = 2, k2 = 4;

  // Define the expected values
  std::vector<int> nums1_cp = nums1;
  std::vector<int> nums2_cp = nums2;
  std::sort(nums1_cp.begin(), nums1_cp.end(), std::greater<int>());
  std::sort(nums2_cp.begin(), nums2_cp.end(), std::greater<int>());

  EXPECT_EQ(heaps::kth_largest(nums1, k1), nums1_cp.at(k1 - 1));
  EXPECT_EQ(heaps::kth_largest(nums2, k2), nums2_cp.at(k2 - 1));
}

TEST(TestHeaps, TestKClosest) {
  // Define the inputs
  const std::vector<std::vector<int>> points1 = { {1,3}, {-2,2} };
  const std::vector<std::vector<int>> points2 = { {3,3}, {5,-1}, {-2,4} };
  const int k1 = 1, k2 = 2;

  // Define the expected values
  const std::vector<std::vector<int>> expected1 = { {-2,2} };
  const std::vector<std::vector<int>> expected2 = { {3,3}, {-2,4} };

  // Create the result vectors
  const std::vector<std::vector<int>> result1 = heaps::k_closest(points1, k1);
  const std::vector<std::vector<int>> result2 = heaps::k_closest(points2, k2);

  // Check the first result.
  EXPECT_EQ(result1.size(), expected1.size());
  for ( const auto& point : result1 ) {
    EXPECT_NE(std::find(expected1.cbegin(), expected1.cend(), point), expected1.cend());
  }

  // Check the second result. The expected element much exist in the result
  // vector, but order does not matter.
  EXPECT_EQ(result2.size(), expected2.size());
  for ( const auto& point : result2 ) {
    EXPECT_NE(std::find(expected2.cbegin(), expected2.cend(), point), expected2.cend());
  }
}

TEST(TestHeaps, TestKClosestFast) {
  // Define the inputs
  const std::vector<std::vector<int>> points1 = { {1,3}, {-2,2} };
  const std::vector<std::vector<int>> points2 = { {3,3}, {5,-1}, {-2,4} };
  const int k1 = 1, k2 = 2;

  // Define the expected values
  const std::vector<std::vector<int>> expected1 = { {-2,2} };
  const std::vector<std::vector<int>> expected2 = { {3,3}, {-2,4} };

  // Create the result vectors
  const std::vector<std::vector<int>> result1 = heaps::k_closest_fast(points1, k1);
  const std::vector<std::vector<int>> result2 = heaps::k_closest_fast(points2, k2);

  // Check the first result.
  EXPECT_EQ(result1.size(), expected1.size());
  for ( const auto& point : result1 ) {
    EXPECT_NE(std::find(expected1.cbegin(), expected1.cend(), point), expected1.cend());
  }

  // Check the second result. The expected element much exist in the result
  // vector, but order does not matter.
  EXPECT_EQ(result2.size(), expected2.size());
  for ( const auto& point : result2 ) {
    EXPECT_NE(std::find(expected2.cbegin(), expected2.cend(), point), expected2.cend());
  }
}

TEST(TestHeaps, TestKthLargestElementInStream) {
  // Experimenting with the "dummy" template class.
  heaps::MyTemplateClass<int> intObject(10);
  heaps::MyTemplateClass<double> doubleObject(3.14);

  // Test case 1:
  const std::vector<int> init1 = { 4, 5, 8, 2 };
  const std::vector<int> vals1 = { 3, 5, 10, 9, 4 };
  const std::vector<int> expected1 = { 4, 5, 5, 8, 8 };
  heaps::KthLargest<int> obj(3, init1);

  for ( size_t idx = 0; idx < vals1.size(); idx++ ) {
    EXPECT_EQ(obj.add(vals1.at(idx)), expected1.at(idx));
  }

  // Test case 2:
  const std::vector<int> init2 = { 7, 7, 7, 7, 8, 3 };
  const std::vector<int> vals2 = { 2, 10, 9, 9 };
  const std::vector<int> expected2 = { 7, 7, 7, 8 };
  heaps::KthLargest<int> obj2(4, init2);

  for ( size_t idx = 0; idx < vals2.size(); idx++ ) {
    EXPECT_EQ(obj2.add(vals2.at(idx)), expected2.at(idx));
  }
}