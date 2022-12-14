#include <iostream>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 二叉树的最近公共祖先
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉树的最近公共祖先
 *
 * @details
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且
 * x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * @par 示例
 *
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 *
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 *
 * @see [leetcode-236](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)
 */
class LowestCommonAncestor {
 public:
  TreeNode<int>* lowestCommonAncestor1(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    std::vector<TreeNode<int>*> pPath, pRes;
    path(root, p, pPath, pRes);
    std::vector<TreeNode<int>*> qPath, qRes;
    path(root, q, qPath, qRes);

    return ancestor(pRes, qRes);
  }

  TreeNode<int>* lowestCommonAncestor2(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }

    TreeNode<int>* left = lowestCommonAncestor2(root->left, p, q);
    TreeNode<int>* right = lowestCommonAncestor2(root->right, p, q);

    if (left != nullptr && right != nullptr) {
      return root;
    }

    return left == nullptr ? right : left;
  }

 private:
  void path(TreeNode<int>* root, TreeNode<int>* p, std::vector<TreeNode<int>*>& paths,
            std::vector<TreeNode<int>*>& res) {
    paths.push_back(root);

    if (root == p) {
      res = paths;
      return;
    }

    if (root->left != nullptr) {
      path(root->left, p, paths, res);
      paths.pop_back();
    }

    if (root->right != nullptr) {
      path(root->right, p, paths, res);
      paths.pop_back();
    }
  };

  TreeNode<int>* ancestor(std::vector<TreeNode<int>*>& v1, std::vector<TreeNode<int>*>& v2) {
    TreeNode<int>* root = nullptr;
    for (size_t i = 0; i < v1.size() && i < v2.size(); i++) {
      if (v1.at(i) == v2.at(i)) {
        root = v1.at(i);
      } else {
        break;
      }
    }

    return root;
  }
};
}  // namespace tree
}  // namespace algo