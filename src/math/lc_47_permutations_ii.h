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
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 * @par 示例
 *
 * 输入：nums = [1,1,2]
 * 输出：[[1,1,2],[1,2,1],[2,1,1]]
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * @see [leetcode-47](https://leetcode.cn/problems/permutations-ii/)
 */
class PermuteII {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

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
      if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) {
        continue;
      }

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