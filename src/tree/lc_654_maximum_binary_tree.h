#include <iostream>
#include <stack>
#include <vector>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 最大二叉树
 */

namespace algo {
namespace tree {
/**
 * @brief 最大二叉树
 *
 * @details
 * 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
 * 创建一个根节点，其值为 nums 中的最大值。
 * 递归地在最大值 左边 的 子数组前缀上 构建左子树。
 * 递归地在最大值 右边 的 子数组后缀上 构建右子树。
 * 返回 nums 构建的 最大二叉树 。
 *
 * @par 示例
 *
 * 输入：nums = [3,2,1,6,0,5]
 * 输出：[6,3,5,null,2,0,null,null,1]
 *
 * 输入：nums = [3,2,1]
 * 输出：[3,null,2,null,1]
 *
 * @see [leetcode-654](https://leetcode.cn/problems/maximum-binary-tree/)
 */
class MaximumBinaryTree {
 public:
  TreeNode<int>* constructMaximumBinaryTree1(std::vector<int>& nums) { return construct(nums, 0, nums.size() - 1); }

  /**
   * @ingroup monotonic-stack
   */
  TreeNode<int>* constructMaximumBinaryTree2(std::vector<int>& nums) {
    std::stack<int> stacks;
    std::vector<TreeNode<int>*> trees(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      trees[i] = new TreeNode<int>(nums[i]);

      while (!stacks.empty() && nums[i] > nums[stacks.top()]) {
        trees[i]->left = trees[stacks.top()];
        stacks.pop();
      }

      if (!stacks.empty()) {
        trees[stacks.top()]->right = trees[i];
      }

      stacks.push(i);
    }

    TreeNode<int>* root = trees[stacks.top()];
    while (!stacks.empty()) {
      root = trees[stacks.top()];
      stacks.pop();
    }

    return root;
  }

 private:
  TreeNode<int>* construct(std::vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    int maxId = left;
    for (int i = left + 1; i <= right; i++) {
      if (nums[maxId] < nums[i]) {
        maxId = i;
      }
    }

    TreeNode<int>* root = new TreeNode<int>(nums[maxId]);
    root->left = construct(nums, left, maxId - 1);
    root->right = construct(nums, maxId + 1, right);

    return root;
  }
};
}  // namespace tree
}  // namespace algo