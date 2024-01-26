#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 零钱兑换 II
 */
namespace algo {
namespace array {
/**
 * @brief 零钱兑换 II
 *
 * @details
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 * 假设每一种面额的硬币有无限个。
 * 题目数据保证结果符合 32 位带符号整数。
 *
 * @par 示例
 *
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 *
 * @see
 *
 * [leetcode-518](https://leetcode.cn/problems/coin-change-ii/)
 */

class CoinChangeII {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int change(int amount, std::vector<int>& coins) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }

    return dp[amount];
  }
};
}  // namespace array
}  // namespace algo