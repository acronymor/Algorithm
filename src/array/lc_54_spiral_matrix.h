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
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素
 *
 * @par 示例
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 * @see [leetcode-54](https://leetcode.cn/problems/spiral-matrix/)
 */

class SpiralOrder {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;
    res.reserve(matrix.size() * matrix.at(0).size());
    size_t row_cnt = matrix.size();
    size_t col_cnt = matrix.at(0).size();

    size_t cnt = std::min(row_cnt, col_cnt) / 2;
    int k = 0;

    while (k < cnt) {
      for (int j = k; j < col_cnt - k - 1; j++) {
        res.push_back(matrix[k][j]);
      }

      for (int i = k; i < row_cnt - k - 1; i++) {
        res.push_back(matrix[i][col_cnt - k - 1]);
      }

      for (int j = col_cnt - k - 1; j > k; j--) {
        res.push_back(matrix[row_cnt - k - 1][j]);
      }

      for (int i = row_cnt - k - 1; i > k; i--) {
        res.push_back(matrix[i][k]);
      }

      k++;
    }

    if (res.size() == row_cnt * col_cnt) {
      return res;
    }

    if (row_cnt < col_cnt) {
      for (int j = cnt; j <= col_cnt - cnt - 1; j++) {
        res.push_back(matrix[cnt][j]);
      }
    } else {
      for (int i = cnt; i <= row_cnt - cnt - 1; i++) {
        res.push_back(matrix[i][cnt]);
      }
    }

    return res;
  }
};
}  // namespace array
};  // namespace algo