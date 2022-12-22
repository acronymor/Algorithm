#include <iostream>
#include <queue>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的层序遍历
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的层序遍历
 *
 * @details
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 * 输入：root = []
 * 输出：[]
 *
 * @see [leetcode-102](https://leetcode.cn/problems/binary-tree-level-order-traversal/)
 */
class LevelorderTraversal {
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

    return res;
  }
};
}  // namespace tree
}  // namespace algo