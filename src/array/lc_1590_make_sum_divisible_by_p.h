#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 使数组和能被 P 整除
 */

namespace algo {
namespace array {

/**
 * @brief 使数组和能被 P 整除
 *
 * @details
 * 给你一个正整数数组 nums，请你移除最短子数组（可以为空），使得剩余元素的 和 能被 p 整除。 不允许将整个数组都移除。
 * 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
 * 子数组 定义为原数组中连续的一组元素。
 *
 * @par 示例
 *
 * 输入：nums = [3,1,4,2], p = 6
 * 输出：1
 *
 * 输入：nums = [6,3,5,2], p = 9
 * 输出：2
 *
 * @see [leetcode-974](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)
 */

class MinSubarray {
 public:
  /**
   * @ingroup prefix-sum
   */
  int solve(std::vector<int>& nums, int k) {
    int total = 0;
    for (auto num : nums) {
      total = (total + num) % k;
    }

    int modulus = total % k;
    if (modulus == 0) {
      return 0;
    }

    std::unordered_map<int, int> hash;
    int res = std::numeric_limits<int>::max();
    total = 0;
    hash[total] = -1;

    for (int i = 0; i < nums.size(); i++) {
      total = (total + nums[i]) % k;

      int r = total % k;
      int tmp = (r - modulus + k) % k;

      if (hash.find(tmp) != hash.end()) {
        int start = hash[tmp] + 1;
        int end = i;
        res = std::min(res, end - start + 1);
      }

      hash[r] = i;
    }

    return res == nums.size() ? -1 : res;
  }
};
}  // namespace array
};  // namespace algo