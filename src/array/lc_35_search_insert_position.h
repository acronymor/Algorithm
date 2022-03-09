#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 搜索插入位置
 */

namespace algo {
namespace array {

/**
 * @brief 搜索插入位置
 *
 * @details
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 请必须使用时间复杂度为 O(log n) 的算法。
 *
 * @par 示例
 *
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 *
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 *
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 *
 * @see [leetcode-704](https://leetcode.cn/problems/binary-search/)
 */

class SearchInsertPosition {
 public:
  int searchInsert1(std::vector<int>& nums, int target) {
    return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }

  /**
   * @ingroup binary-search
   */
  int searchInsert2(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
      int mid = left + ((right - left) >> 2);
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid;
      } else {
        return mid;
      }
    }

    return right;
  }
};
}  // namespace array
};  // namespace algo