#include <iostream>
#include <queue>
#include <algorithm>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的层序遍历 II
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的层序遍历 II
 *
 * @details
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[15,7],[9,20],[3]]
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 * 输入：root = []
 * 输出：[]
 *
 * @see [leetcode-107](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)
 */
class LevelorderTraversalII {
 public:
  std::vector<std::vector<int>> levelorderTraversal(TreeNode<int>* root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    std::deque<TreeNode<int>*> queues;
    queues.push_back(root);

    while (!queues.empty()) {
      size_t size = queues.size();
      std::vector<int> v;

      for (size_t i = 0; i < size; i++) {
        TreeNode<int>* node = queues.front();
        queues.pop_front();
        v.push_back(node->val);

        if (node->left != nullptr) {
          queues.push_back(node->left);
        }

        if (node->right != nullptr) {
          queues.push_back(node->right);
        }
      }

      res.push_back(v);
    }

    std::reverse(res.begin(), res.end());
    return res;
  }
};
}  // namespace tree
}  // namespace algo