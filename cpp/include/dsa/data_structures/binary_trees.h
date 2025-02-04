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
} // end namespace dsa::data_structures::binary_trees