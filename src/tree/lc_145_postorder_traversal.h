#include <iostream>
#include <stack>
#include <algorithm>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的后序遍历
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的后序遍历
 *
 * @details
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *
 * @par 示例
 *
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
 *
 * 输入：root = []
 * 输出：[]
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 * @see [leetcode-145](https://leetcode.cn/problems/binary-tree-postorder-traversal/)
 */
class PostorderTraversal {
 public:
  std::vector<int> postorderTraversal1(TreeNode<int>* root) {
    std::vector<int> res;
    traversal(root, res);
    return res;
  }

  std::vector<int> postorderTraversal2(TreeNode<int>* root) {
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    std::stack<TreeNode<int>*> stacks;
    stacks.push(root);

    while (!stacks.empty()) {
      TreeNode<int>* node = stacks.top();
      stacks.pop();

      res.push_back(node->val);

      if (node->left != nullptr) {
        stacks.push(node->left);
      }

      if (node->right != nullptr) {
        stacks.push(node->right);
      }
    }

    std::reverse(res.begin(), res.end());
    return res;
  }

 private:
  void traversal(TreeNode<int>* root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }

    traversal(root->left, res);
    traversal(root->right, res);
    res.push_back(root->val);
  }
};
}  // namespace tree
}  // namespace algo