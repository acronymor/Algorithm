#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 和可被 K 整除的子数组
 */

namespace algo {
namespace array {

/**
 * @brief 和可被 K 整除的子数组
 *
 * @details
 * 给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的（连续、非空） 子数组 的数目。
 * 子数组 是数组的 连续 部分。
 *
 * @par 示例
 *
 * 输入：nums = [4,5,0,-2,-3,1], k = 5
 * 输出：7
 *
 * 输入: nums = [5], k = 9
 * 输出: 0
 *
 * @see [leetcode-974](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)
 */

class SubarraysDivByK {
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

      int modulus = (total % k + k) % k;
      if (hash.find(modulus) != hash.end()) {
        res += hash[modulus];
      }

      hash[modulus]++;
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo