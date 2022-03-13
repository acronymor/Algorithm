#include <iostream>
#include <stack>
#include <vector>

/**
 * @namespace array
 * @brief 盛最多水的容器
 */

namespace algo {
namespace array {
/**
 * @brief 下一个更大元素 II
 *
 * @details
 * 给定一个循环数组 nums（ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。
 * 数字x的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
 * 如果不存在，则输出 -1。
 *
 * @par 示例
 *
 * 输入: nums = [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数；
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 *
 * 输入: nums = [1,2,3,4,3]
 * 输出: [2,3,4,-1,4]
 *
 * @see [leetcode-503](https://leetcode.cn/problems/next-greater-element-ii/)
 */

class NextGreaterElementII {
 public:
  /**
   * @ingroup monotonic-stack
   */
  std::vector<int> nextGreaterElements(std::vector<int>& nums) {
    std::vector<int> res(nums.size(), -1);
    std::stack<int> stacks;

    int capacity = nums.size();

    for (int i = 0; i < 2 * capacity; i++) {
      int j = i % capacity;
      while (!stacks.empty() && nums[j] > nums[stacks.top()]) {
        res[stacks.top()] = nums[j];
        stacks.pop();
      }
      stacks.push(j);
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo