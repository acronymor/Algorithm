#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 和为 K 的子数组
 */
namespace algo {
namespace array {
/**
 * @brief 和为 K 的子数组
 *
 * @details
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
 *
 * @par 示例
 *
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 *
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 *
 * @see
 * [leetcode-560](https://leetcode.cn/problems/subarray-sum-equals-k/)
 */

class SubarraySum {
 public:
  /**
   * @ingroup prefix-sum
   */
  int solve(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> hash;
    int total = 0, res = 0;

    hash[total] = 1;

    for (int i = 0; i < nums.size(); i++) {
      total += nums[i];

      if (hash.find(total - k) != hash.end()) {
        res += hash[total - k];
      }

      hash[total]++;
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo