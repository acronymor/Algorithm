#include <cmath>
#include <iostream>
#include <unordered_set>

/**
 * @namespace math
 * @brief 单调递增的数字
 */

namespace algo {
namespace math {
/**
 * @brief 快乐数
 *
 * @details
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 *
 * @par 示例
 *
 * 输入: n = 10
 * 输出: 9
 *
 * 输入: n = 1234
 * 输出: 1234
 *
 * @see [leetcode-738](https://leetcode.cn/problems/monotone-increasing-digits/)
 */

class MonotoneIncreasingDigits {
 public:
  // overtime
  int solve1(int n) {
    for (int i = n; i >= 0; i--) {
      if (isMonotone(i)) {
        return i;
      }
    }

    return n;
  }

  /**
   * @ingroup greedy
   */
  int solve2(int n) {
    std::string str = std::to_string(n);
    int pos = str.size();

    for (int i = str.size() - 1; i > 0; i--) {
      if (str[i - 1] > str[i]) {
        str[i - 1]--;
        pos = i;
      }
    }

    for (int i = pos; i < str.size(); i++) {
      str[i] = '9';
    }

    return std::stoi(str);
  }

 private:
  bool isMonotone(int n) {
    int pre = 10;

    while (n > 0) {
      int cur = n % 10;
      if (cur > pre) {
        return false;
      }
      pre = cur;
      n = n / 10;
    }

    return true;
  }
};

}  // namespace math
}  // namespace algo