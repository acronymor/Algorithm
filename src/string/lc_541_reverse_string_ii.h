#include <iostream>
#include <string>

/**
 * @namespace string
 * @brief 反转字符串 II
 */

namespace algo {
namespace string {

/**
 * @brief 反转字符串 II
 *
 * @details
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 *
 * @par 示例
 *
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 *
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 *
 * @see [leetcode-541](https://leetcode.cn/problems/reverse-string-ii/)
 */

class ReverseStringII {
 public:
  std::string reverseString(std::string s, int k) {
    for (size_t i = 0; i < s.size(); i += (2 * k)) {
      if (i + k < s.size()) {
        std::reverse(s.begin() + i, s.begin() + i + k);
      } else {
        std::reverse(s.begin() + i, s.end());
      }
    }

    return s;
  }
};
}  // namespace string
}  // namespace algo