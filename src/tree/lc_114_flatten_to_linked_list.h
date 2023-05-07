#include <iostream>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 二叉树展开为链表
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树展开为链表
 *
 * @details
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 *
 * @par 示例
 *
 * 输入：root = [1,2,5,3,4,null,6]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6]
 *
 * 输入：root = []
 * 输出：[]
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 * @see [leetcode-114](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)
 */
class FlattenToLinkedList {
 public:
  void flatten(TreeNode<int>* root) {
    if (root == nullptr) {
      return;
    }

    flatten(root->left);

    TreeNode<int>* right = root->right;
    root->right = root->left;
    root->left = nullptr;

    while (root->right != nullptr) {
      root = root->right;
    }

    flatten(right);
    root->right = right;
  }
};
}  // namespace tree
}  // namespace algo