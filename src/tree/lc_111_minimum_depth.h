#include <iostream>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的最小深度
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的最小深度
 *
 * @details
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 *
 * 输入：root = [1]
 * 输出： 1
 *
 * 输入：root = []
 * 输出： 0
 *
 * @see [leetcode-111](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)
 */
class MinDepth {
 public:
  int minDepth1(TreeNode<int>* root) {
    if (root == nullptr) {
      return 0;
    }

    int leftH = minDepth1(root->left);
    int rightH = minDepth1(root->right);

    if (root->left == nullptr || root->right == nullptr) {
      return leftH + rightH + 1;
    }
    return std::min(leftH, rightH) + 1;
  }

  int minDepth2(TreeNode<int>* root) {
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

        if (node->left == nullptr && node->right == nullptr) {
          return depth;
        }
      }
    }

    return depth;
  }
};
}  // namespace tree
}  // namespace algo
