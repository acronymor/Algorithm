#include <iostream>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的右视图
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的右视图
 *
 * @details
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 * @par 示例
 *
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1,3,4]
 *
 * 输入: [1,null,3]
 * 输出: [1,3]
 *
 * 输入：root = []
 * 输出：[]
 *
 * @see [leetcode-199](https://leetcode.cn/problems/binary-tree-right-side-view/)
 */
class RightSideView {
 public:
  std::vector<int> rightSideView(TreeNode<int>* root) {
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    std::deque<TreeNode<int>*> queues;
    queues.push_back(root);

    while (!queues.empty()) {
      size_t size = queues.size();

      for (size_t i = 0; i < size; i++) {
        TreeNode<int>* node = queues.front();
        queues.pop_front();

        if (i == size - 1) {
          res.push_back(node->val);
        }

        if (node->left != nullptr) {
          queues.push_back(node->left);
        }

        if (node->right != nullptr) {
          queues.push_back(node->right);
        }
      }
    }

    return res;
  }
};
}  // namespace tree
}  // namespace algo