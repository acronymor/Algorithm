#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @namespace math
 * @brief 子集 II
 */

namespace algo {
namespace math {
/**
 * @brief 子集 II
 *
 * @details
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 * @see [leetcode-90](https://leetcode.cn/problems/subsets-ii/)
 */
class SubsetsII {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> v;
    std::vector<std::vector<int>> res;
    backtracking(nums, 0, v, res);
    return res;
  }

 private:
  void backtracking(const std::vector<int>& nums, int start, std::vector<int>& v, std::vector<std::vector<int>>& res) {
    res.push_back(v);

    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i - 1] == nums[i]) {
        continue;
      }
      v.push_back(nums[i]);
      backtracking(nums, i + 1, v, res);
      v.pop_back();
    }
  }
};
}  // namespace math
}  // namespace algo