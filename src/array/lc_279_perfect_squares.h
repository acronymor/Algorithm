#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace array
 * @brief 完全平方数
 */

namespace algo {
namespace array {

/**
 * @brief 完全平方数
 *
 * @details
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16
 * 都是完全平方数，而 3 和 11 不是。
 *
 * @par 示例
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 * @see [leetcode-279](https://leetcode.cn/problems/perfect-squares/)
 */

class NumSquares {
 public:
  int numSquares(int n) {
    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i * i; j <= n; j++) {
        dp[j] = std::min(dp[j], dp[j - i * i] + 1);
      }
    }

    return dp[n];
  }
};
}  // namespace array
}  // namespace algo