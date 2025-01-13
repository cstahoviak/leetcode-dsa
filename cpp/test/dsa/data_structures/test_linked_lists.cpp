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
  std::cout << "Creating the Singly Linked List." << std::endl;
  SinglyLinkedList list1(5);
  std::cout << "Finding the middle value." << std::endl;
  ListNode* middle1 = middle_node(list1.head());
  std::cout << "Evaluating expected value." << std::endl;
  EXPECT_EQ(middle1->val, 3);

  // Test Case 2:
  SinglyLinkedList list2(6);
  ListNode* middle2 = middle_node(list2.head());
  EXPECT_EQ(middle2->val, 4);
}