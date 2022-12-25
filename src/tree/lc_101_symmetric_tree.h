#include <iostream>

#include "common.h"

/**
 * @namespace tree
 * @brief 对称二叉树
 */

namespace algo {
namespace tree {
/**
 * @brief 对称二叉树
 *
 * @details
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 * @par 示例
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 * @see [leetcode-101](https://leetcode.cn/problems/symmetric-tree/)
 */
class IsSymmetric {
 public:
  bool isSymmetric(TreeNode<int>* root) {
    if (root == nullptr) {
      return true;
    }

    return compare(root->left, root->right);
  }

 private:
  bool compare(TreeNode<int>* left, TreeNode<int>* right) {
    if (left == nullptr && right != nullptr) {
      return false;
    } else if (left != nullptr && right == nullptr) {
      return false;
    } else if (left == nullptr && right == nullptr) {
      return true;
    } else if (left->val != right->val) {
      return false;
    } else {
      return compare(left->left, right->right) && compare(left->right, right->left);
    }
  }
};
}  // namespace tree
}  // namespace algo