#include <iostream>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 删除二叉搜索树中的节点
 */

namespace algo {
namespace tree {
/**
 * @brief 删除二叉搜索树中的节点
 *
 * @details
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 一般来说，删除节点可分为两个步骤：
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 *
 * @par 示例
 *
 * 输入：root = [5,3,6,2,4,null,7], key = 3
 * 输出：[5,4,6,2,null,null,7]
 *
 * 输入: root = [5,3,6,2,4,null,7], key = 0
 * 输出: [5,3,6,2,4,null,7]
 *
 * @see [leetcode-450](https://leetcode.cn/problems/delete-node-in-a-bst/)
 */
class DeleteNode {
 public:
  TreeNode<int>* deleteNode(TreeNode<int>* root, int val) {
    if (root == nullptr) {
      return root;
    }

    if (root->val == val) {
      if (root->right == nullptr) {
        return root->left;
      }

      TreeNode<int>* cur = root->right;

      while (cur->left != nullptr) {
        cur = cur->left;
      }

      std::swap(cur->val, root->val);
    }

    root->left = deleteNode(root->left, val);
    root->right = deleteNode(root->right, val);

    return root;
  }
};
}  // namespace tree
}  // namespace algo