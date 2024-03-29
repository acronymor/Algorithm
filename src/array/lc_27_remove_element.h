#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 移除元素
 */

namespace algo {
namespace array {

/**
 * @brief 移除元素
 *
 * @details
 * 给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 *
 * @par 示例
 *
 * 输入: nums = [3,2,2,3], val = 3
 * 输出: 2, nums = [2,2]
 *
 * 解释: 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 * 你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或
 * nums = [2,2,0,0]，也会被视作正确答案。
 *
 * 输入：nums = [0,1,2,2,3,0,4,2], val = 2
 * 输出：5, nums = [0,1,4,0,3]
 *
 * 解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 * 注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
 *
 * @see [leetcode-27](https://leetcode.cn/problems/remove-element/)
 */

class RemoveElement {
 public:
  int removeElement(std::vector<int>& nums, int value) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != value) {
        nums[j++] = nums[i];
      }
    }

    return j;
  }
};
}  // namespace array
};  // namespace algo