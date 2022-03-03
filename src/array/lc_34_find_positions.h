#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief 在排序数组中查找元素的第一个和最后一个位置
 *
 * @details
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 * @par 示例
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * @see [leetcode-34](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)
 */

namespace algo {
namespace array {
namespace {
int findLeft(std::vector<int>& nums, int target) {
  int left = 0, right = nums.size() - 1;
  int res = 0;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      res = mid;
      right = mid - 1;
    }
  }

  return (nums.empty() || nums[res] != target) ? -1 : res;
}

int findRight(std::vector<int>& nums, int target) {
  int left = 0, right = nums.size() - 1;
  int res = 0;
  while (left <= right) {
    int mid = left + ((right - left) >> 2);
    if (nums[mid] <= target) {
      res = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return (nums.empty() || nums[res] != target) ? -1 : res;
}
}  // namespace

class FindPositions {
 public:
  std::vector<int> searchRange1(std::vector<int>& nums, int target) {
    int start = -1, end = -1;
    bool flag = true;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        if (flag) {
          start = i;
          flag = false;
        }
        end = i;
      }
    }
    return {start, end};
  }

  std::vector<int> searchRange2(std::vector<int>& nums, int target) {
    int start = findLeft(nums, target);
    if (start == -1) {
      return {start, start};
    }

    int end = findRight(nums, target);
    return {start, end};
  }
};
}  // namespace array
}  // namespace algo