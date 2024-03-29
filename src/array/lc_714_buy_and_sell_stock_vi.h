#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 买卖股票的最佳时机 VI
 */

namespace algo {
namespace array {
/**
 * @brief 买卖股票的最佳时机 VI
 *
 * @details
 * 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 返回获得利润的最大值。
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 *
 * @par 示例
 *
 * 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
 * 输出：8
 * 解释：能够达到的最大利润:
 * 在此处买入 prices[0] = 1
 * 在此处卖出 prices[3] = 8
 * 在此处买入 prices[4] = 4
 * 在此处卖出 prices[5] = 9
 * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
 *
 * 输入：prices = [1,3,7,5,10,3], fee = 3
 * 输出：6
 *
 * @see [leetcode-714](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
 */
class MaxProfitVI {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve(std::vector<int>& prices, int fee) {
    if (prices.size() == 0) {
      return 0;
    }

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
    dp[0][0] = 0 - prices[0];

    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }

    return dp[prices.size() - 1][1];
  }
};
}  // namespace array
}  // namespace algo