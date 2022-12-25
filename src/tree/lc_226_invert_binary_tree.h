#include <iostream>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 翻转二叉树
 */

namespace algo {
namespace tree {
/**
 * @brief 翻转二叉树
 *
 * @details
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 *
 * @par 示例
 *
 * 输入：root = [4,2,7,1,3,6,9]
 * 输出：[4,7,2,9,6,3,1]
 *
 * 输入：root = [2,1,3]
 * 输出：[2,3,1]
 *
 * 输入：root = []
 * 输出：[]
 *
 * @see [leetcode-226](https://leetcode.cn/problems/invert-binary-tree/)
 */
class InvertTree {
 public:
  TreeNode<int>* invertTree1(TreeNode<int>* root) {
    if (root == nullptr) {
      return root;
    }

    std::swap(root->left, root->right);
    invertTree1(root->left);
    invertTree1(root->right);

    return root;
  }

  TreeNode<int>* invertTree2(TreeNode<int>* root) {
    if (root == nullptr) {
      return root;
    }

    TreeNode<int>* left = invertTree2(root->left);
    TreeNode<int>* right = invertTree2(root->right);

    root->left = right;
    root->right = left;

    return root;
  }

  TreeNode<int>* invertTree3(TreeNode<int>* root) {
    if (root == nullptr) {
      return root;
    }

    std::deque<TreeNode<int>*> queues;
    queues.push_back(root);

    while (!queues.empty()) {
      int size = queues.size();

      for (size_t i = 0; i < size; i++) {
        TreeNode<int>* node = queues.front();
        queues.pop_front();

        std::swap(node->left, node->right);

        if (node->left != nullptr) {
          queues.push_back(node->left);
        }

        if (node->right != nullptr) {
          queues.push_back(node->right);
        }
      }
    }

    return root;
  }
};
}  // namespace tree
}  // namespace algo