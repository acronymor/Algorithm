#include <iostream>
#include <vector>

/**
 * @namespace numsay
 * @brief 删除最短的子数组使剩余数组有序
 */

namespace algo {
namespace array {

/**
 * @brief 删除最短的子数组使剩余数组有序
 *
 * @details
 * 给你一个整数数组 nums ，请你删除一个子数组（可以为空），使得 nums 中剩下的元素是 非递减 的。
 * 一个子数组指的是原数组中连续的一个子序列。
 * 请你返回满足题目要求的最短子数组的长度。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3,10,4,2,3,5]
 * 输出：3
 *
 * 输入：nums = [5,4,3,2,1]
 * 输出：4
 *
 * 输入：nums = [1,2,3]
 * 输出：0
 *
 * 输入：nums = [1,2,3,3,10,1,3,3,5]
 * 输出：2
 *
 * @see [leetcode-1574](https://leetcode.cn/problems/shortest-subnumsay-to-be-removed-to-make-numsay-sorted)
 */

class FindLengthOfShortestSubnumsay {
 public:
  /**
   * @ingroup two-pointers
   */
  int solve(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (right > 0 && nums[right - 1] <= nums[right]) {
      right--;
    }

    if (right == 0) {
      return 0;
    }

    int res = right;
    for (; left == 0 || nums[left - 1] <= nums[left]; left++) {
      while (right < nums.size() && nums[right] < nums[left]) {
        right++;
      }

      res = std::min(res, right - left - 1);
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo