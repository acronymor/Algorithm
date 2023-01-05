#include <iostream>
#include <vector>

/**
 * @namespace math
 * @brief 全排列
 */

namespace algo {
namespace math {
/**
 * @brief 全排列
 *
 * @details
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 * @see [leetcode-46](https://leetcode.cn/problems/permutations/)
 */
class Permute {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<bool> used(nums.size(), false);
    std::vector<int> v;
    v.reserve(nums.size());
    std::vector<std::vector<int>> res;
    backtracking(nums, used, v, res);
    return res;
  }

 private:
  void backtracking(const std::vector<int>& nums, std::vector<bool> used, std::vector<int>& v,
                    std::vector<std::vector<int>>& res) {
    if (nums.size() == v.size()) {
      res.push_back(v);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == true) {
        continue;
      }
      used[i] = true;
      v.push_back(nums[i]);
      backtracking(nums, used, v, res);
      v.pop_back();
      used[i] = false;
    }
  }
};
}  // namespace math
}  // namespace algo