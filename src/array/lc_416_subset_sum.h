#include <iostream>
#include <numeric>
#include <vector>

/**
 * @namespace array
 * @brief 分割等和子集
 */
namespace algo {
namespace array {
/**
 * @brief 分割等和子集
 *
 * @details
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * @par 示例
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 *
 * @see [leetcode-416](https://leetcode.cn/problems/partition-equal-subset-sum/)
 */

class CanPartition {
 public:
  /**
   * @ingroup dynamic-programming
   */
  bool solve1(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }

    int target = sum / 2;

    std::vector<std::vector<int>> dp(nums.size(), std::vector(target, 0));
    for (int j = nums[0]; j <= target; j++) {
      dp[0][j] = nums[0];
    }

    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j <= target; j++) {
        if (j < nums[i]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
        }
      }
    }

    return dp[nums.size() - 1][target] == target;
  }

  /**
   * @ingroup dynamic-programming
   */
  bool solve2(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }

    int target = sum / 2;
    std::vector<int> dp(10001, 0);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = target; j >= nums[i]; j--) {
        dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }

    return dp[target] == target;
  }
};
}  // namespace array
}  // namespace algo