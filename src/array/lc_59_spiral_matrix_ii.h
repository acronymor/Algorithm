#include <iostream>
#include <limits>
#include <vector>

/**
 * @brief 螺旋矩阵 II
 *
 * @details
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 * @par 示例
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 * @see [leetcode-59](https://leetcode.cn/problems/spiral-matrix-ii/)
 */

namespace algo {
namespace array {
class SpiralOrderII {
 public:
  std::vector<std::vector<int>> spiralOrder(int n) {
    std::vector<std::vector<int>> matrix;
    matrix.reserve(n);

    int row_cnt = n;
    int col_cnt = n;
    int cnt = n / 2;
    int number = 1;

    for (int i = 0; i < row_cnt; i++) {
      std::vector<int> row(col_cnt, 0);
      matrix.push_back(row);
    }

    int k = 0;
    while (k < cnt) {
      for (int j = k; j < col_cnt - k - 1; j++) {
        matrix[k][j] = number++;
      }

      for (int i = k; i < row_cnt - k - 1; i++) {
        matrix[i][col_cnt - k - 1] = number++;
      }

      for (int j = col_cnt - k - 1; j > k; j--) {
        matrix[row_cnt - k - 1][j] = number++;
      }

      for (int i = row_cnt - k - 1; i > k; i--) {
        matrix[i][k] = number++;
      }

      k++;
    }

    for (int i = cnt; i <= row_cnt - cnt - 1; i++) {
      matrix[i][cnt] = number++;
    }

    return matrix;
  }
};
}  // namespace array
};  // namespace algo