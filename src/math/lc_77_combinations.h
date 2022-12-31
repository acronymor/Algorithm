#include <iostream>
#include <vector>

/**
 * @namespace math
 * @brief 组合
 */

namespace algo {
namespace math {
/**
 * @brief 组合
 *
 * @details
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 你可以按 任何顺序 返回答案。
 *
 * @par 示例
 *
 * 输入：n = 4, k = 2
 * 输出： [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 * @see [leetcode-77](https://leetcode.cn/problems/combinations/)
 */
class Combine {
 public:
  /**
   * @ingroup backtracking
   */
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<int> v;
    std::vector<std::vector<int>> res;
    backtracking(n, k, 1, v, res);
    return res;
  }

 private:
  void backtracking(int n, int k, int start, std::vector<int>& v, std::vector<std::vector<int>>& res) {
    if (v.size() == k) {
      res.push_back(v);
      return;
    }

    for (int i = start; i <= n; i++) {
      v.push_back(i);
      backtracking(n, k, i + 1, v, res);
      v.pop_back();
    }
  }
};
}  // namespace math
}  // namespace algo