#include <iostream>
#include <string>

/**
 * @namespace math
 * @brief 数字转换为十六进制数
 */

namespace algo {
namespace math {
/**
 * @brief 数字转换为十六进制数
 *
 * @details
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 *
 * @par 示例
 *
 * 输入: 26
 * 输出: "1a"
 *
 * 输入: -1
 * 输出: "ffffffff"
 *
 * @see [leetcode-405](https://leetcode.cn/problems/convert-a-number-to-hexadecimal/)
 */
class ConvertNumber {
 public:
  std::string toHex(int num) {
    if (num == 0) {
      return "0";
    }

    int hex = 16;

    std::string res;
    const std::string table = "0123456789abcdef";

    long tmp = num < 0 ? (1l << 32) + num : num;

    while (tmp > 0) {
      res = table[tmp % hex] + res;
      tmp /= hex;
    }

    return res;
  }
};
}  // namespace math
}  // namespace algo