#include <iostream>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 二叉搜索树的最近公共祖先
 */

namespace algo {
namespace tree {
/**
 * @brief 二叉搜索树的最近公共祖先
 *
 * @details
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且
 * x 的深度尽可能大（一个节点也可以是它自己的祖先）。” 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 * @par 示例
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 *
 * @see [leetcode-235](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)
 */
class LowestCommonAncestor {
 public:
  TreeNode<int>* lowestCommonAncestor1(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    if (p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor1(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor1(root->right, p, q);
    } else {
      return root;
    }
  }

  TreeNode<int>* lowestCommonAncestor2(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    while (root != nullptr) {
      if (p->val < root->val && q->val < root->val) {
        root = root->left;
      } else if (p->val > root->val && q->val > root->val) {
        root = root->right;
      } else {
        return root;
      }
    }
    return root;
  }

  TreeNode<int>* lowestCommonAncestor3(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
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
};
}  // namespace tree
}  // namespace algo