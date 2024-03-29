#include <iostream>
#include <numeric>
#include <vector>

/**
 * @namespace array
 * @brief 目标和
 */

namespace algo {
namespace array {

/**
 * @brief 目标和
 *
 * @details
 * 给你一个整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 * @par 示例
 *
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 * @see [leetcode-494](https://leetcode.cn/problems/target-sum/)
 */

class FindTargetSumWays {
 public:
  /**
   *  @ingroup dynamic-programming
   */
  int solve1(std::vector<int>& nums, int t) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int target = (sum + t) / 2;

    if (target < 0 || (sum + t) % 2 != 0) {
      return 0;
    }

    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(target + 1, 0));
    /*
     * dp[0][0] = 1 不把数字放入到大小为0的背包里面，这种情况算一种组合，所以赋值为 1
     * nums[0] == 0 是一种特殊情况
     * dp[0][0] 可以表示为 将 nums[0] 不放入大小为 0 的背包的和将 nums[0] 放入到大小为 0 的背包中，所以需要赋值为 2
     */
    dp[0][0] = 1;
    if (nums[0] <= target) {
      dp[0][nums[0]] = nums[0] == 0 ? dp[0][0] + 1 : 1;
    }

    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j <= target; j++) {
        if (nums[i] > j) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
        }
      }
    }

    return dp[nums.size() - 1][target];
  }

  /**
   *  @ingroup dynamic-programming
   */
  int solve2(std::vector<int>& nums, int t) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int target = (t + sum) / 2;

    if (target < 0 || (t + sum) % 2 != 0) {
      return 0;
    }

    std::vector<int> dp(target + 1, 0);

    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = target; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];
      }
    }

    return dp[target];
  }

  /**
   *  @ingroup backtracking
   */
  int solve3(std::vector<int>& nums, int t) {
    std::vector<int> res;
    backtracking(res, nums, t, 0, 0);
    return res.size();
  }

 private:
  void backtracking(std::vector<int>& res, std::vector<int>& nums, int target, int index, int sum) {
    if (index == nums.size()) {
      if (sum == target) {
        res.push_back(1);
      }
    } else {
      backtracking(res, nums, target, index + 1, sum + nums[index]);
      backtracking(res, nums, target, index + 1, sum - nums[index]);
    }
  }
};
}  // namespace array
}  // namespace algo