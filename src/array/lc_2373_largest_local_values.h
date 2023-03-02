#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 矩阵中的局部最大值
 */

namespace algo {
namespace array {

/**
 * @brief 矩阵中的局部最大值
 *
 * @details
 * 给你一个大小为 n x n 的整数矩阵 grid 。 生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：
 * maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
 * 换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。
 * 返回生成的矩阵。
 *
 * @par 示例
 *
 * 输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
 * 输出：[[9,9],[8,6]]
 *
 * 输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
 * 输出：[[2,2,2],[2,2,2],[2,2,2]]
 *
 * @see [leetcode-2373](https://leetcode.cn/problems/largest-local-values-in-a-matrix/)
 */

class LargestLocal {
 public:
  std::vector<std::vector<int>> solve(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> res(grid.size() - 2, std::vector<int>(grid.size() - 2, 0));
    for (int i = 0; i < grid.size() - 2; i++) {
      for (int j = 0; j < grid[i].size() - 2; j++) {
        res[i][j] = max(grid, i, j);
      }
    }

    return res;
  }

 private:
  int max(std::vector<std::vector<int>>& grid, int m, int n) {
    int res = 0;
    for (int i = m; i <= m + 2; i++) {
      for (int j = n; j <= n + 2; j++) {
        if (grid[i][j] > res) {
          res = grid[i][j];
        }
      }
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo
