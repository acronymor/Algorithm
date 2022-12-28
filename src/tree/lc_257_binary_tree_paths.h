#include <iostream>
#include <string>
#include <vector>

#include "common.h"

/**
 * @namespace tree
 * @brief 二叉树的所有路径
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的所有路径
 *
 * @details
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 叶子节点 是指没有子节点的节点。
 *
 * @par 示例
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 * @see [leetcode-257](https://leetcode.cn/problems/binary-tree-paths/)
 */
class BinaryTreePaths {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::string> binaryTreePaths(TreeNode<int>* root) {
    std::string path;
    std::vector<std::string> res;
    traversal(root, path, res);
    return res;
  }

 private:
  void traversal(TreeNode<int>* root, std::string path, std::vector<std::string>& res) {
    path.append(std::to_string(root->val));
    if (root->left == nullptr && root->right == nullptr) {
      res.push_back(path);
      return;
    }

    if (root->left != nullptr) {
      path.append("->");
      traversal(root->left, path, res);
      path.erase(path.end() - 2, path.end());
    }

    if (root->right != nullptr) {
      path.append("->");
      traversal(root->right, path, res);
      path.erase(path.end() - 2, path.end());
    }
  }
};
}  // namespace tree
}  // namespace algo