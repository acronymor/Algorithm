#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace math
 * @brief 组合总和 Ⅳ
 */

namespace algo {
namespace math {
/**
 * @brief 组合总和 IV
 *
 * @details
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target
 * 的元素组合的个数。 题目数据保证答案符合 32 位整数范围。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 *
 * 输入：nums = [9], target = 3
 * 输出：0
 *
 * @see [leetcode-377](https://leetcode.cn/problems/combination-sum-iv/)
 */
class CombineSumIV {
 public:
  /**
   * @ingroup backtracking
   */
  int combineSum1(std::vector<int>& candidates, int target) {
    int res = backtracking(candidates, target);
    return res;
  }

  /**
   * @ingroup dynamic-programming
   */
  int combineSum2(std::vector<int>& candidates, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; i++) {
      for (int j = 0; j < candidates.size(); j++) {
        if (i - candidates[j] >= 0 && dp[i] < std::numeric_limits<int>::max() - dp[i - candidates[j]]) {
          dp[i] += dp[i - candidates[j]];
        }
      }
    }
    return dp[target];
  }

 private:
  int backtracking(const std::vector<int>& candidates, int target) {
    if (target < 0) {
      return 0;
    }

    if (target == 0) {
      return 1;
    }

    int res = 0;
    for (int i = 0; i < candidates.size(); i++) {
      res += backtracking(candidates, target - candidates[i]);
    }

    return res;
  }
};
}  // namespace math
}  // namespace algo