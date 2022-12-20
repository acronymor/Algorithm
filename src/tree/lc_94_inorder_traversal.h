#include <iostream>
#include <stack>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的中序遍历
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的中序遍历
 *
 * @details
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 *
 * @par 示例
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 *
 * 输入：root = []
 * 输出：[]
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 * @see [leetcode-94](https://leetcode.cn/problems/binary-tree-inorder-traversal/)
 */
class InorderTraversal {
 public:
  std::vector<int> inorderTraversal1(TreeNode<int>* root) {
    std::vector<int> res;
    traversal(root, res);
    return res;
  }

  std::vector<int> inorderTraversal2(TreeNode<int>* root) {
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    std::stack<TreeNode<int>*> stacks;
    TreeNode<int>* cur = root;
    while (cur != nullptr || !stacks.empty()) {
      if (cur != nullptr) {
        stacks.push(cur);
        cur = cur->left;
      } else {
        cur = stacks.top();
        stacks.pop();
        res.push_back(cur->val);
        cur = cur->right;
      }
    }

    return res;
  }

 private:
  void traversal(TreeNode<int>* root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }

    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);
  }
};
}  // namespace tree
}  // namespace algo