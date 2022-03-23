#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 四数之和 II
 */

namespace algo {
namespace array {
/**
 * @brief 四数之和 II
 *
 * @details
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 * @par 示例
 *
 * 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * 输出：2
 * 解释：
 * 两个元组如下：
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
 *
 * 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * 输出：1
 *
 * @see [leetcode-454](https://leetcode.cn/problems/4sum-ii/)
 */

class FourSumII {
 public:
  /**
   * @ingroup hash-table
   */
  int fourSum(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
    std::unordered_map<int, int> maps;
    for (auto m : nums1) {
      for (auto n : nums2) {
        maps[m + n]++;
      }
    }

    int count = 0;

    for (auto m : nums3) {
      for (auto n : nums4) {
        int target = 0 - (m + n);
        auto itr = maps.find(target);
        if (itr != maps.end()) {
          count += maps[target];
        }
      }
    }

    return count;
  }
};
}  // namespace array
}  // namespace algo