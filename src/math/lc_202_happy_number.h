#include <cmath>
#include <iostream>
#include <unordered_set>

/**
 * @namespace math
 * @brief 快乐数
 */

namespace algo {
namespace math {
namespace {
int calSum(int num) {
  int res = 0;
  while (num != 0) {
    res += std::pow(num % 10, 2);
    num /= 10;
  }

  return res;
}
}  // namespace

/**
 * @brief 快乐数
 *
 * @details
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 「快乐数」 定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 * @par 示例
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 * 输入：n = 2
 * 输出：false
 *
 * @see [leetcode-202](https://leetcode.cn/problems/happy-number/)
 */

class IsHappy {
 public:
  bool isHappy(int n) {
    std::unordered_set<int> sets;
    while (true) {
      n = calSum(n);

      // if (sets.contains(n)) {
      if (sets.count(n) > 0) {
        break;
      }

      if (n == 1) {
        return true;
      }

      sets.insert(n);
    }

    return false;
  }
};

}  // namespace math
}  // namespace algo