#include <iostream>
#include <limits>
#include <vector>

/**
 * @brief 长度最小的子数组
 *
 * @details
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
 * 并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 * @par 示例
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 * @see [leetcode-209](https://leetcode.cn/problems/minimum-size-subarray-sum/)
 */

namespace algo {
namespace array {
class MinSubArrayLen {
 public:
  // overtime
  int minSubArrayLen1(std::vector<int>& nums, int target) {
    int res = std::numeric_limits<int>::max();
    for (int j = 0; j < nums.size(); j++) {
      int i = j, sum = 0;
      while (sum < target && i >= 0) {
        sum += nums[i--];
      }
      if (sum >= target) {
        res = std::min(res, j - i);
      }
    }

    return res == std::numeric_limits<int>::max() ? 0 : res;
  }

  int minSubArrayLen2(std::vector<int>& nums, int target) {
    int res = std::numeric_limits<int>::max();
    int sum = 0;
    for (int j = 0, i = 0; j < nums.size(); j++) {
      sum += nums[j];
      while (sum >= target) {
        res = std::min(res, j - i + 1);
        sum -= nums[i];
        i++;
      }
    }

    return res == std::numeric_limits<int>::max() ? 0 : res;
  }
};
}  // namespace array
}  // namespace algo