#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace array
 * @brief 买卖股票的最佳时机 II
 */

namespace algo {
namespace array {
/**
 * @brief 买卖股票的最佳时机 II
 *
 * @details
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 返回 你能获得的 最大 利润 。
 *
 * @par 示例
 *
 * 输入：[7,1,5,3,6,4]
 * 输出：7
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
 * 总利润为 4 + 3 = 7 。
 *
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 *
 * @see [leetcode-122](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)
 */
class MaxProfitII {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve(std::vector<int>& prices) {
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
  }
};
}  // namespace array
}  // namespace algo