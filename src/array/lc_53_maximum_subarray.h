#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace array
 * @brief 最大子数组和
 */

namespace algo {
namespace array {

/**
 * @brief 最大子数组和
 *
 * @details
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 *
 * @par 示例
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 * 输入：nums = [1]
 * 输出：1
 *
 * @see [leetcode-53](https://leetcode.cn/problems/maximum-subarray/)
 */

class MaxSubArray {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int maxSubArray1(std::vector<int>& nums) {
    int dp[nums.size()];
    int res = dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
      if (dp[i] > res) {
        res = dp[i];
      }
    }

    return res;
  }

  /**
   * @ingroup greedy
   */
  int maxSubArray2(std::vector<int>& nums) {
    int res = std::numeric_limits<int>::min();

    for (int i = 0, cnt = 0; i < nums.size(); i++) {
      cnt += nums[i];
      if (res < cnt) {
        res = cnt;
      }

      if (cnt < 0) {
        cnt = 0;
      }
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo