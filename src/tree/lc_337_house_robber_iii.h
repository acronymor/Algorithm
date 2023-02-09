#include <iostream>
#include <vector>

#include "tree/common.h"

/**
 * @namespace tree
 * @brief 打家劫舍 III
 */

namespace algo {
namespace tree {

/**
 * @brief 打家劫舍 III
 *
 * @details
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。
 * 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树。
 * 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。 给定二叉树的 root 。
 * 返回 在不触动警报的情况下，小偷能够盗取的最高金额 。
 *
 * @par 示例
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 *      偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * @see [leetcode-337](https://leetcode.cn/problems/house-robber-iii/)
 */

class RobIII {
 public:
  int solve(TreeNode<int>* root) {
    // dp[0] not steal root
    // dp[1] steal root
    std::vector<int> dp = preorder(root);
    return std::max(dp[0], dp[1]);
  }

  std::vector<int> preorder(TreeNode<int>* root) {
    if (root == nullptr) {
      return {0, 0};
    }

    std::vector<int> left = preorder(root->left);
    std::vector<int> right = preorder(root->right);

    int v1 = std::max(left[0], left[1]) + std::max(right[0], right[1]);
    int v2 = root->val + left[0] + right[0];

    return {v1, v2};
  }
};
}  // namespace tree
}  // namespace algo