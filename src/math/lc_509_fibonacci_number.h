#include <iostream>
#include <unordered_set>

/**
 * @namespace math
 * @brief 斐波那契数
 */
namespace algo {
namespace math {
/**
 * @brief 斐波那契数
 *
 * @details
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1
 * 开始，后面的每一项数字都是前面两项数字的和。也就是：
 *
 * @code
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 * 给定 n ，请计算 F(n) 。
 * @endcode
 *
 * @par 示例
 *
 * 输入：n = 2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 *
 * 输入：n = 3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 *
 * @see [leetcode-509](https://leetcode.cn/problems/fibonacci-number/)
 */
class Fib {
 public:
  int fib1(int n) {
    if (n < 2) {
      return n;
    }

    int a = 0, b = 0, c = 1;
    for (int i = 2; i <= n; i++) {
      a = b;
      b = c;
      c = a + b;
    }

    return c;
  }

  int fib2(int n) {
    if (n == 0 || n == 1) {
      return n;
    }

    return fib2(n - 1) + fib2(n - 2);
  }
};
}  // namespace math
}  // namespace algo