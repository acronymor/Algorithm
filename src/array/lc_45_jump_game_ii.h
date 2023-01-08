#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 跳跃游戏
 */

namespace algo {
namespace array {

/**
 * @brief 跳跃游戏
 *
 * @details
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 * 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
 * 0 <= j <= nums[i]
 * i + j < n
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 *
 * @par 示例
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 * @see [leetcode-45](https://leetcode.cn/problems/jump-game-ii/)
 */

class CanJumpII {
 public:
  /**
   * @ingroup backtracking
   */
  int jump(std::vector<int>& nums) {
    int cur = nums[0], next = cur;
    int res = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
      next = std::max(next, nums[i] + i);
      if (i == cur) {
        cur = next;
        res++;
      }
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo