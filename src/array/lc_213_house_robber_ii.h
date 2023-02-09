#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 打家劫舍 II
 */

namespace algo {
namespace array {

/**
 * @brief 打家劫舍 II
 *
 * @details
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈，
 * 这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *
 * @par 示例
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 *      偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * @see [leetcode-213](https://leetcode.cn/problems/house-robber-ii/)
 */

class RobII {
 public:
  int solve(std::vector<int>& nums) {
    if (nums.size() <= 3) {
      int res = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > res) {
          res = nums[i];
        }
      }
      return res;
    }

    std::vector<int> dp1(nums.size() - 1, 0);
    dp1[0] = nums[0];
    dp1[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size() - 1; i++) {
      dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i]);
    }

    std::vector<int> dp2(nums.size(), 0);
    dp2[1] = nums[1];
    dp2[2] = std::max(nums[1], nums[2]);
    for (int i = 3; i < nums.size(); i++) {
      dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }

    return std::max(dp1[nums.size() - 2], dp2[nums.size() - 1]);
  }
};
}  // namespace array
}  // namespace algo