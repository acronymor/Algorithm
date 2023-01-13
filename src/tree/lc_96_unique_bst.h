#include <iostream>
#include <vector>

/**
 * @namespace tree
 * @brief 不同的二叉搜索树
 */

namespace algo {
namespace tree {
/**
 * @brief 不同的二叉搜索树
 *
 * @details
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树
 * 有多少种？返回满足题意的二叉搜索树的种数。
 *
 * @par 示例
 *
 * 输入：n = 3
 * 输出：5
 *
 * 输入：n = 1
 * 输出：1
 *
 * @see [leetcode-96](https://leetcode.cn/problems/unique-binary-search-trees/)
 */
class NumTrees {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
}  // namespace tree
}  // namespace algo