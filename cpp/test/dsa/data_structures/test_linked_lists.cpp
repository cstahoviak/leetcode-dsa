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
#include "dsa/data_structures/linked_lists.h"

#include <gtest/gtest.h>

using namespace dsa::data_structures::linked_lists;

TEST(TestLinkedListsAlgorithms, TestMiddleNode) {
  // Test Case 1:
  SinglyLinkedList list1(5);
  const ListNode* middle1 = list1.middle_node();
  EXPECT_EQ(middle1->val, 3);

  // Test Case 2:
  SinglyLinkedList list2(6);
  const ListNode* middle2 = list2.middle_node();
  EXPECT_EQ(middle2->val, 4);
}

TEST(TestLinkedListsAlgorithms, TestRemoveDuplicates) {
  // Test Case 1:
  const std::vector<int> nums {1, 1, 1, 2, 3, 3, 4, 5, 5, 5};
  const std::vector<int> expected {1, 2, 3, 4, 5};
  SinglyLinkedList list(nums);
  list.remove_duplicates();

  EXPECT_EQ(list.values(), expected);
}

TEST(TestLinkedListsAlgorithms, TestReverseSublist) {
  GTEST_SKIP();

  // Test Case 1:
  const std::vector<int> nums {1, 2, 3, 4, 5};
  const std::vector<int> expected {1, 4, 3, 2, 5};
  SinglyLinkedList list(nums);
  list.reverse_sublist(2, 4);
  EXPECT_EQ(list.values(), expected);

  // Test Case 2:
  const std::vector<int> nums2 { 5 };
  const std::vector<int> expected2 { 5 };
  SinglyLinkedList list2(nums2);
  list2.reverse_sublist(1, 1);
  EXPECT_EQ(list2.values(), expected2);
}