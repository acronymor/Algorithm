#include <iostream>
#include <limits>
#include <vector>

/**
 * @namespace array
 * @brief 螺旋矩阵
 */

namespace algo {
namespace array {

/**
 * @brief 螺旋矩阵
 *
 * @details
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 * @par 示例
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 * @see [leetcode-54](https://leetcode.cn/problems/spiral-matrix/)
 */

class NQueens {
 public:
  std::vector<std::vector<std::string>> solve(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> v(n, std::string(n, '.'));
    backtracking(n, 0, res, v);
    return res;
  }

 private:
  bool isValid(std::vector<std::string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }

  void backtracking(int n, int row, std::vector<std::vector<std::string>>& res, std::vector<std::string>& v) {
    if (row == n) {
      res.push_back(v);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (!isValid(v, row, i, n)) {
        continue;
      }

      v[row][i] = 'Q';
      backtracking(n, row + 1, res, v);
      v[row][i] = '.';
    }
  }
};
}  // namespace array
};  // namespace algo