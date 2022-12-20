#include <iostream>
#include <stack>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的前序遍历
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的前序遍历
 *
 * @details
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 * @par 示例
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 * 输入：root = []
 * 输出：[]
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 * @see [leetcode-144](https://leetcode.cn/problems/binary-tree-preorder-traversal/)
 */
class PreorderTraversal {
 public:
  std::vector<int> preorderTraversal1(TreeNode<int>* root) {
    std::vector<int> res;
    traversal(root, res);
    return res;
  }

  std::vector<int> preorderTraversal2(TreeNode<int>* root) {
    if (root == nullptr) {
      return {};
    }

    std::stack<TreeNode<int>*> stacks;
    stacks.push(root);

    std::vector<int> res;
    while (!stacks.empty()) {
      TreeNode<int>* node = stacks.top();
      stacks.pop();
      res.push_back(node->val);

      if (node->right != nullptr) {
        stacks.push(node->right);
      }

      if (node->left != nullptr) {
        stacks.push(node->left);
      }
    }

    return res;
  }

 private:
  void traversal(TreeNode<int>* root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }

    res.push_back(root->val);
    traversal(root->left, res);
    traversal(root->right, res);
  }
};
}  // namespace tree
}  // namespace algo