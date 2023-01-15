#include <iostream>
#include <numeric>
#include <vector>

/**
 * @namespace array
 * @brief 最后一块石头的重量 II
 */

namespace algo {
namespace array {

/**
 * @brief 最后一块石头的重量 II
 *
 * @details
 * 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
 * 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
 * - 如果 x == y，那么两块石头都会被完全粉碎；
 * - 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 * 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
 *
 * @par 示例
 *
 * 输入：stones = [2,7,4,1,8,1]
 * 输出：1
 * 解释：
 * 组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
 * 组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
 * 组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
 * 组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 *
 * 输入：stones = [31,26,33,21,40]
 * 输出：5
 *
 * @see [leetcode-1049](https://leetcode.cn/problems/last-stone-weight-ii/)
 */

class LastStoneWeightII {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve1(std::vector<int>& stones) {
    int sum = std::accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;

    std::vector<std::vector<int>> dp(stones.size(), std::vector<int>(target + 1, 0));
    for (int j = stones[0]; j <= target; j++) {
      dp[0][j] = stones[0];
    }

    for (int i = 1; i < stones.size(); i++) {
      for (int j = 0; j <= target; j++) {
        if (j < stones[i]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
        }
      }
    }

    return (sum - dp[stones.size() - 1][target]) - dp[stones.size() - 1][target];
  }

  /**
   * @ingroup dynamic-programming
   */
  int solve2(std::vector<int>& stones) {
    std::vector<int> dp(15001, 0);
    int sum = std::accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    for (int i = 0; i < stones.size(); i++) {
      for (int j = target; j >= stones[i]; j--) {
        dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }

    return sum - dp[target] - dp[target];
  }
};
}  // namespace array
};  // namespace algo