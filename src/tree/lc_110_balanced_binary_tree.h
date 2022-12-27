#include <iostream>

#include "common.h"

/**
 * @namespace tree
 * @brief 平衡二叉树
 */

namespace algo {
namespace tree {
/**
 * @brief 平衡二叉树
 *
 * @details
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 本题中，一棵高度平衡二叉树定义为：
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 * 输入：root = []
 * 输出：true
 *
 * @see [leetcode-110](https://leetcode.cn/problems/balanced-binary-tree/)
 */
class IsBalanced {
 public:
  bool isBalanced(TreeNode<int>* root) { return height(root) != -1; }

 private:
  int height(TreeNode<int>* root) {
    if (root == nullptr) {
      return 0;
    }

    int left = height(root->left);
    if (left == -1) {
      return -1;
    }

    int right = height(root->right);
    if (right == -1) {
      return -1;
    }

    if (std::abs(left - right) > 1) {
      return -1;
    }

    return std::max(left, right) + 1;
  }
};
}  // namespace tree
}  // namespace algo