#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 不同路径 II
 */

namespace algo {
namespace array {

/**
 * @brief 不同路径 II
 *
 * @details
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 * @par 示例
 *
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 *
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 *
 * @see [leetcode-63](https://leetcode.cn/problems/unique-paths-ii/)
 */

class UniquePathsII {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int uniquePaths(std::vector<std::vector<int>>& grid) {
    int dp[grid.size()][grid[0].size()];
    dp[0][0] = grid[0][0] == 0 ? 1 : 0;

    for (int i = 1; i < grid.size(); i++) {
      if (grid[i][0] == 1) {
        dp[i][0] = 0;
      } else {
        dp[i][0] = dp[i - 1][0];
      }
    }

    for (int j = 1; j < grid[0].size(); j++) {
      if (grid[0][j] == 1) {
        dp[0][j] = 0;
      } else {
        dp[0][j] = dp[0][j - 1];
      }
    }

    for (int i = 1; i < grid.size(); i++) {
      for (int j = 1; j < grid[i].size(); j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        if (grid[i][j] == 1) {
          dp[i][j] = 0;
        }
      }
    }

    return dp[grid.size() - 1][grid[0].size() - 1];
  }
};
}  // namespace array
}  // namespace algo