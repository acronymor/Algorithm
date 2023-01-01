#include <iostream>
#include <vector>

/**
 * @namespace math
 * @brief 组合总和 III
 */

namespace algo {
namespace math {
/**
 * @brief 组合总和 III
 *
 * @details
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 * 只使用数字1到9
 * 每个数字 最多使用一次
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 *
 * @par 示例
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 *
 * @see [leetcode-216](https://leetcode.cn/problems/combination-sum-iii/)
 */
class CombineSumIII {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> combineSum(int n, int k) {
    std::vector<int> v;
    std::vector<std::vector<int>> res;
    backtracking(9, k, n, 1, v, res);
    return res;
  }

 private:
  void backtracking(int n, int k, int target, int start, std::vector<int>& v, std::vector<std::vector<int>>& res) {
    if (target < 0) {
      return;
    }

    if (v.size() == k && target == 0) {
      res.push_back(v);
      return;
    }

    for (int i = start; i <= n; i++) {
      v.push_back(i);
      backtracking(n, k, target - i, i + 1, v, res);
      v.pop_back();
    }
  }
};
}  // namespace math
}  // namespace algo