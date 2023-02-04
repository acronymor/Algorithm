#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace array
 * @brief 零钱兑换
 */

namespace algo {
namespace array {

/**
 * @brief 零钱兑换
 *
 * @details
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 *
 * @par 示例
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * @see [leetcode-322](https://leetcode.cn/problems/coin-change/)
 */

class CoinChange {
 public:
  int solve1(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());

    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        if (dp[j - coins[i]] != std::numeric_limits<int>::max()) {
          dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
        }
      }
    }

    if (dp[amount] == std::numeric_limits<int>::max()) {
      return -1;
    }

    return dp[amount];
  }

  int solve2(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());

    dp[0] = 0;
    for (int j = 1; j <= amount; j++) {
      for (int i = 0; i < coins.size(); i++) {
        if (j >= coins[i] && dp[j - coins[i]] != std::numeric_limits<int>::max()) {
          dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
        }
      }
    }

    if (dp[amount] == std::numeric_limits<int>::max()) {
      return -1;
    }

    return dp[amount];
  }
};
}  // namespace array
}  // namespace algo