#include <iostream>
#include <vector>

/**
 * @brief 有序数组的平方
 *
 * @details
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 * @par 示例
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 * @see [leetcode-977](https://leetcode.cn/problems/squares-of-a-sorted-array/)
 */

namespace algo {
namespace array {
class SortedSquares {
 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> res(nums.size(), 0);
    int i = 0, j = nums.size() - 1, k = j;
    while (i <= j) {
      int left = nums[i] * nums[i];
      int right = nums[j] * nums[j];

      if (left < right) {
        res[k--] = right;
        j--;
      } else {
        res[k--] = left;
        i++;
      }
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo