#include <iostream>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的层平均值
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的层平均值
 *
 * @details
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 *
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 *
 * @see [leetcode-637](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)
 */
class AverageOfLevels {
 public:
  std::vector<double> averageOfLevels(TreeNode<int>* root) {
    std::vector<double> res(0.0);
    if (root == nullptr) {
      return res;
    }

    std::deque<TreeNode<int>*> queues;
    queues.push_back(root);

    while (!queues.empty()) {
      size_t size = queues.size();

      double num = 0.0;
      for (size_t i = 0; i < size; i++) {
        TreeNode<int>* node = queues.front();
        queues.pop_front();

        num += node->val;
        if (i == size - 1) {
          res.push_back(num / size);
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