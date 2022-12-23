#include <iostream>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的最大深度
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的最大深度
 *
 * @details
 * 给定一个二叉树，找出其最大深度。
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：3
 *
 * 输入：root = [1]
 * 输出： 1
 *
 * 输入：root = []
 * 输出： 0
 *
 * @see [leetcode-104](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)
 */
class MaxDepth {
 public:
  int maxDepth1(TreeNode<int>* root) {
    if (root == nullptr) {
      return 0;
    }

    int leftH = maxDepth1(root->left);
    int rightH = maxDepth1(root->right);

    return std::max(leftH, rightH) + 1;
  }

  int maxDepth2(TreeNode<int>* root) {
    int depth = 0;
    if (root == nullptr) {
      return depth;
    }

    std::deque<TreeNode<int>*> queues;
    queues.push_back(root);

    while (!queues.empty()) {
      size_t size = queues.size();
      depth++;

      for (size_t i = 0; i < size; i++) {
        TreeNode<int>* node = queues.front();
        queues.pop_front();

        if (node->left != nullptr) {
          queues.push_back(node->left);
        }
        if (node->right != nullptr) {
          queues.push_back(node->right);
        }
      }
    }

    return depth;
  }
};
}  // namespace tree
}  // namespace algo
