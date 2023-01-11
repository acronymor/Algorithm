#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 不同路径
 */

namespace algo {
namespace array {

/**
 * @brief 不同路径
 *
 * @details
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 *
 * @par 示例
 *
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 输入：m = 3, n = 2
 * 输出：3
 *
 * @see [leetcode-62](https://leetcode.cn/problems/unique-paths/)
 */

class UniquePaths {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int j = 0; j < n; j++) {
      dp[0][j] = 1;
    }

    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};
}  // namespace array
}  // namespace algo