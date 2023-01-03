#include <iostream>
#include <vector>

/**
 * @namespace math
 * @brief 子集
 */

namespace algo {
namespace math {
/**
 * @brief 子集
 *
 * @details
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 * @see [leetcode-78](https://leetcode.cn/problems/subsets/)
 */
class Subsets {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<int> v;
    std::vector<std::vector<int>> res;
    backtracking(nums, 0, v, res);
    return res;
  }

 private:
  void backtracking(const std::vector<int>& nums, int start, std::vector<int>& v, std::vector<std::vector<int>>& res) {
    res.push_back(v);

    for (int i = start; i < nums.size(); i++) {
      v.push_back(nums[i]);
      backtracking(nums, i + 1, v, res);
      v.pop_back();
    }
  }
};
}  // namespace math
}  // namespace algo