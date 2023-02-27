#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 递减元素使数组呈锯齿状
 */

namespace algo {
namespace array {

/**
 * @brief 递减元素使数组呈锯齿状
 *
 * @details
 * 给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。
 * 如果符合下列情况之一，则数组 A 就是 锯齿数组：
 * - 每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
 * - 或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
 * 返回将数组 nums 转换为锯齿数组所需的最小操作次数。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3]
 * 输出：2
 * 解释：我们可以把 2 递减到 0，或把 3 递减到 1。
 *
 * 输入：nums = [9,6,1,6,2]
 * 输出：4
 *
 * @see [leetcode-1144](https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag)
 */

class MovesToMakeZigzag {
 public:
  int solve(std::vector<int>& nums) { return std::min(helper(nums, 0), helper(nums, 1)); }

 private:
  int helper(std::vector<int>& nums, int start) {
    int res = 0;

    for (int i = start; i < nums.size(); i += 2) {
      int cnt = 0;
      if (i - 1 >= 0) {
        cnt = std::max(cnt, nums[i] - nums[i - 1] + 1);
      }

      if (i + 1 < nums.size()) {
        cnt = std::max(cnt, nums[i] - nums[i + 1] + 1);
      }

      res += cnt;
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo