/**
 * @file test_dfs.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for the Depth First Search (DFS) algorithms.
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/algorithms/dfs.h"

#include <gtest/gtest.h>

using namespace dsa::algorithms;

TEST(TestDepthFirstSearch, TestMinDepth) {
  // Create the example tree (starting from the leaves).
  dfs::TreeNode<int> fifteen(15), seven(7), nine(9);
  dfs::TreeNode<int> twenty(20, &fifteen, &seven);
  dfs::TreeNode<int> three(3, &nine, &twenty);

  EXPECT_EQ(dfs::min_depth(&three), 2);
}

