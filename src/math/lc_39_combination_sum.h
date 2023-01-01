#include <iostream>
#include <vector>

/**
 * @namespace math
 * @brief 组合总和
 */

namespace algo {
namespace math {
/**
 * @brief 组合总和
 *
 * @details
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
 * 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。 candidates 中的 同一个 数字可以 无限制重复被选取
 * 。如果至少一个数字的被选数量不同，则两种组合是不同的。 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 *
 * @par 示例
 *
 * 输入：candidates = [2,3,6,7], target = 7
 * 输出：[[2,2,3],[7]]
 *
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * 输入: candidates = [2], target = 1
 * 输出: []
 *
 * @see [leetcode-39](https://leetcode.cn/problems/combination-sum/)
 */
class CombineSum {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> combineSum(std::vector<int>& candidates, int target) {
    std::vector<int> v;
    std::vector<std::vector<int>> res;
    backtracking(candidates, target, res, v, 0);
    return res;
  }

 private:
  void backtracking(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& res,
                    std::vector<int>& v, int start) {
    if (target < 0) {
      return;
    }

    if (target == 0) {
      res.push_back(v);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      v.push_back(candidates[i]);
      backtracking(candidates, target - candidates[i], res, v, i);
      v.pop_back();
    }
  }
};
}  // namespace math
}  // namespace algo