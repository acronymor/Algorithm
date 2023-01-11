#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 使用最小花费爬楼梯
 */

namespace algo {
namespace array {

/**
 * @brief 使用最小花费爬楼梯
 *
 * @details
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i
 * 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。 你可以选择从下标为 0 或下标为 1
 * 的台阶开始爬楼梯。 请你计算并返回达到楼梯顶部的最低花费。
 *
 * @par 示例
 *
 * 输入：cost = [10,15,20]
 * 输出：15
 *
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 *
 * @see [leetcode-746](https://leetcode.cn/problems/min-cost-climbing-stairs/)
 */

class MinCostClimbingStairs {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int minCostClimbingStairs(std::vector<int>& cost) {
    int dp[cost.size() + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= cost.size(); i++) {
      dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[cost.size()];
  }
};
}  // namespace array
}  // namespace algo