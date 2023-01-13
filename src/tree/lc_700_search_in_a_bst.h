#include <iostream>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 二叉搜索树中的搜索
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉搜索树中的搜索
 *
 * @details
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
 *
 * @par 示例
 *
 * 输入：root = [4,2,7,1,3], val = 2
 * 输出：[2,1,3]
 *
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[]
 *
 * @see [leetcode-700](https://leetcode.cn/problems/search-in-a-binary-search-tree/)
 */
class SearchBST {
 public:
  TreeNode<int>* searchBST(TreeNode<int>* root, int val) {
    if (root == nullptr || root->val == val) {
      return root;
    }

    if (root->val > val) {
      return searchBST(root->left, val);
    }

    if (root->val < val) {
      return searchBST(root->right, val);
    }

    return root;
  }
};
}  // namespace tree
}  // namespace algo