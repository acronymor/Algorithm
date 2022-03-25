#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief 反转字符串
 */

namespace algo {
namespace string {

/**
 * @brief 反转字符串
 *
 * @details
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *
 * @par 示例
 *
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 *
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 *
 * @see [leetcode-344](https://leetcode.cn/problems/reverse-string/)
 */

class ReverseString {
 public:
  void reverseString(std::vector<char>& s) {
    char ch;
    for (size_t i = 0, j = s.size() - 1; i < s.size() && i < j; i++, j--) {
      ch = s[i];
      s[i] = s[j];
      s[j] = ch;
    }
  }
};
}  // namespace string
}  // namespace algo