/**
 * @file test_binary_trees.cpp
 * @author Carl Stahoviak
 * @brief Unit tests related to the Binary Tree data structure.
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/data_structures/binary_trees.h"

#include <gtest/gtest.h>

using namespace dsa::data_structures;

TEST(TestBinaryTreees, TestMinDepth) {
  // Create the example tree (starting from the leaves).
  binary_trees::TreeNode<int> fifteen(15), seven(7), nine(9);
  binary_trees::TreeNode<int> twenty(20, &fifteen, &seven);
  binary_trees::TreeNode<int> three(3, &nine, &twenty);

  EXPECT_EQ(binary_trees::min_depth(&three), 2);
}

