#pragma once
/**
 * @file binary_trees.h
 * @author Carl Stahoviak
 * @brief Types and algorithms related to the binary tree data structure.
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

namespace dsa::data_structures::binary_trees
{
  template<typename T>
  struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(T val, TreeNode* left, TreeNode* right) :
      val(val), left(left), right(right) {}
  };

  /**
   * @brief 111. Minimum Depth of a Binary Tree (Easy)
   * https://leetcode.com/problems/minimum-depth-of-binary-tree/
   * 
   * Given a binary tree, find its minimum depth.
   * 
   * The minimum depth is the number of nodes along the shortest path from the
   * root node down to the nearest leaf node.
   * 
   * @tparam T 
   * @param root The root node of the binary tree.
   * @return int The minimum depth of the tree.
   */
  template<typename T>
  int min_depth(TreeNode<T>* root) {
    if ( root == nullptr ) {
      return 0;
    }

    size_t left = min_depth(root->left);
    size_t right = min_depth(root->right);

    size_t min_depth = std::min(left, right) + 1;
    LOG("min depth at node " << root->val << ": " << min_depth);
    
    return std::min(left, right) + 1;
  }

  /**
   * @brief 1026. Maximum Difference Between Node and Ancestor (Medium)
   * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
   * 
   * Given the root of a binary tree, find the maximum value v for which there
   * exist different nodes a and b where v = |a.val - b.val| and a is an
   * ancestor of b.
   * 
   * A node a is an ancestor of b if either:
   *  - any child of a is equal to b or,
   *  - any child of a is an ancestor of b.
   * 
   * TODO: Implement this function and write a unit test.
   * 
   * @tparam T 
   * @param root The root of the binary tree.
   * @return T 
   */
  template<typename T>
  T max_ancestor_diff(TreeNode<T>* root) {
    return {};
  }

  /**
   * @brief 543. Diameter of Binary Tree (Easy)
   * https://leetcode.com/problems/diameter-of-binary-tree/
   * 
   * Given the root of a binary tree, return the diameter of the tree.
   * 
   * The diameter of a binary tree is the length of the longest path between any
   * two nodes in a tree. This path may or may not pass through the root.
   * 
   * The length of a path between two nodes is represented by the number of
   * edges between them.
   * 
   * TODO: This solution is WRONG.
   * 
   * @tparam T 
   * @param root 
   * @return int 
   */
  template<typename T>
  int diameter(TreeNode<T>* root) {
    // Define a lambda to return the max depth of the binary tree.
    auto max_depth = [](TreeNode<T>* root) -> int {
      if (root == nullptr) {
        return 0;
      }

      int ldepth = maxDepth(root->left);
      int rdepth = maxDepth(root->right);

      // The current node contributes 1 to the depth.
      return std::max(ldepth, rdepth) + 1;
    };

    return max_depth(root->left) + max_depth(root->right);
  }

} // end namespace dsa::data_structures::binary_trees