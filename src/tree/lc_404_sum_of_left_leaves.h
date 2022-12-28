#include <iostream>
#include <vector>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 左叶子之和
 */

namespace algo {
namespace tree {
/**
 * @brief 左叶子之和
 *
 * @details
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 * @par 示例
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 * 输入: root = [1]
 * 输出: 0
 *
 * @see [leetcode-404](https://leetcode.cn/problems/sum-of-left-leaves/)
 */
class SumOfLeftLeaves {
 public:
  int sumOfLeftLeaves(TreeNode<int>* root) {
    if (root == nullptr) {
      return 0;
    }

    int res = 0;
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
      res = root->left->val;
    }

    return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};
}  // namespace tree
}  // namespace algo