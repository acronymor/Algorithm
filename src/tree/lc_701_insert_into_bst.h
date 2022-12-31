#include <iostream>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 二叉搜索树中的插入操作
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉搜索树中的插入操作
 *
 * @details
 * 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。
 * 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
 * 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
 *
 * @par 示例
 *
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[4,2,7,1,3,5]
 *
 * 输入：root = [40,20,60,10,30,50,70], val = 25
 * 输出：[40,20,60,10,30,50,70,null,null,25]
 *
 * @see [leetcode-701](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)
 */
class InsertIntoBST {
 public:
  TreeNode<int>* insertIntoBST1(TreeNode<int>* root, int val) {
    if (root == nullptr) {
      return new TreeNode<int>(val);
    }

    if (root->val > val) {
      root->left = insertIntoBST1(root->left, val);
    }

    if (root->val < val) {
      root->right = insertIntoBST1(root->right, val);
    }

    return root;
  }

  TreeNode<int>* insertIntoBST2(TreeNode<int>* root, int val) {
    TreeNode<int>* cur = root;
    while (cur != nullptr) {
      if (val < cur->val) {
        if (cur->left == nullptr) {
          cur->left = new TreeNode<int>(val);
          break;
        }
        cur = cur->left;
      } else {
        if (cur->right == nullptr) {
          cur->right = new TreeNode<int>(val);
          break;
        }
        cur = cur->right;
      }
    }

    if (root == nullptr) {
      root = new TreeNode<int>(val);
    }

    return root;
  }
};
}  // namespace tree
}  // namespace algo