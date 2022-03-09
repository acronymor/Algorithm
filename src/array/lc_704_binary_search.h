#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 二分查找
 */
namespace algo {
namespace array {
/**
 * @brief 二分查找
 *
 * @details
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 * target，如果目标值存在返回下标，否则返回 -1。
 *
 * @par 示例
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 *
 * @see
 *
 * [leetcode-704](https://leetcode.cn/problems/binary-search/)
 */

class BinarySearch {
 public:
  /**
   * @ingroup binary-search
   */
  int search1(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid;
      } else {
        return mid;
      }
    }
    return -1;
  }

  /**
   * @ingroup binary-search
   */
  int search2(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};
}  // namespace array
}  // namespace algo

/**
 * @note
 * 二分查找的关键点在于弄清楚自己的区间定义，是 [)，还是 []
 * - 如果是 [)，那么循环条件就是 `while(left < right)`，`if (nums[mid] > target)` 中的语句是 `right = mid `
 * - 如果是 []，那么循环条件就是 `while(left <= right)`，`if (nums[mid] > target)` 中的语句是 `right = mid - 1`，
 *   来形成一个右闭区间
 */