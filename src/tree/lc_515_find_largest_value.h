#include <iostream>
#include <limits>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 在每个树行中找最大值
 */

namespace algo {
namespace tree {
/**
 * @brief 在每个树行中找最大值
 *
 * @details
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 *
 * @par 示例
 *
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 *
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 *
 * @see [leetcode-515](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)
 */
class LargestValues {
 public:
  std::vector<int> largestValues(TreeNode<int>* root) {
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    std::deque<TreeNode<int>*> queues;
    queues.push_back(root);

    while (!queues.empty()) {
      size_t size = queues.size();

      int num = std::numeric_limits<int>::min();
      for (size_t i = 0; i < size; i++) {
        TreeNode<int>* node = queues.front();
        queues.pop_front();

        if (node->val > num) {
          num = node->val;
        }

        if (node->left != nullptr) {
          queues.push_back(node->left);
        }

        if (node->right != nullptr) {
          queues.push_back(node->right);
        }
      }

      res.push_back(num);
    }

    return res;
  }
};
}  // namespace tree
}  // namespace algo