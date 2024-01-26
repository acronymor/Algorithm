#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @namespace math
 * @brief 组合总和 II
 */

namespace algo {
namespace math {
/**
 * @brief 组合总和 II
 *
 * @details
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 注意：解集不能包含重复的组合。
 *
 * @par 示例
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出: [[1,1,6], [1,2,5], [1,7], [2,6]]
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出: [[1,2,2], [5]]
 *
 * @see [leetcode-40](https://leetcode.cn/problems/combination-sum-ii/)
 */
class CombineSumII {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> combineSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
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
      if (i > start && candidates[i - 1] == candidates[i]) {
        continue;
      }
      v.push_back(candidates[i]);
      backtracking(candidates, target - candidates[i], res, v, i + 1);
      v.pop_back();
    }
  }
};
}  // namespace math
}  // namespace algo

/**
 * @note
 *
 * 什么时候使用 used 数组，什么时候使用 begin 变量
 * 有些朋友可能会疑惑什么时候使用 used 数组，什么时候使用 begin 变量。这里为大家简单总结一下：
 *
 * 排列问题，讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为不同列表时），需要记录哪些数字已经使用过，此时用 used 数组；
 * 组合问题，不讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为相同列表时），需要按照某种顺序搜索，此时使用 begin 变量。
 *
 * https://leetcode.cn/problems/combination-sum/solutions/14697/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
 */