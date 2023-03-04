#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace array
 * @brief 买卖股票的最佳时机
 */

namespace algo {
namespace array {
/**
 * @brief 买卖股票的最佳时机
 *
 * @details
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 *
 * @par 示例
 *
 * 输入：[7,1,5,3,6,4]
 * 输出：5
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 *
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 *
 * @see [leetcode-121](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)
 */
class MaxProfit {
 public:
  /**
   * @ingroup greedy
   */
  int solve1(std::vector<int>& prices) {
    int low = std::numeric_limits<int>::max();
    int res = 0;

    for (int i = 0; i < prices.size(); i++) {
      low = std::min(low, prices[i]);
      res = std::max(res, prices[i] - low);
    }

    return res;
  }

  /**
   * @ingroup dynamic-programming
   */
  int solve2(std::vector<int>& prices) {
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
      dp[i][1] = std::max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[prices.size() - 1][1];
  }
};
}  // namespace array
}  // namespace algo