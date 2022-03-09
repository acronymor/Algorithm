#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 移动零
 */

namespace algo {
namespace array {

/**
 * @brief 移动零
 *
 * @details
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 *
 * @par 示例
 *
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 * 输入: nums = [0]
 * 输出: [0]
 *
 * @see [leetcode-283](https://leetcode.cn/problems/move-zeroes/)
 */

class MoveZeroes {
 public:
  void moveZeroes(std::vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        std::swap(nums[i], nums[j]);
        j++;
      }
    }
  }
};
}  // namespace array
}  // namespace algo