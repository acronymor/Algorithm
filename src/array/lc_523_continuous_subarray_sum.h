#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 连续的子数组和
 */
namespace algo {
namespace array {
/**
 * @brief 连续的子数组和
 *
 * @details
 * 给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
 * - 子数组大小 至少为 2 ，且
 * - 子数组元素总和为 k 的倍数。
 * 如果存在，返回 true； 否则，返回 false 。
 * 如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终视为 k 的一个倍数。
 *
 * @par 示例
 *
 * 输入：nums = [23,2,4,6,7], k = 6
 * 输出：true
 * 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
 *
 * 输入：nums = [23,2,6,4,7], k = 13
 * 输出：false
 *
 * @see
 * [leetcode-523](https://leetcode.cn/problems/continuous-subarray-sum/)
 */

class CheckSubarraySum {
 public:
  /**
   * @ingroup prefix-sum
   */
  int solve(std::vector<int>& nums, int k) {
    int total = 0;
    std::unordered_map<int, int> maps = {{total, -1}};

    for (int i = 0; i < nums.size(); i++) {
      total = (total + nums[i]) % k;
      auto it = maps.find(total);
      if (it != maps.end()) {
        if (i - it->second >= 2) {
          return true;
        }
      } else {
        maps[total] = i;
      }
    }

    return false;
  }
};
}  // namespace array
}  // namespace algo