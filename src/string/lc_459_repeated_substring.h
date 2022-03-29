#include <iostream>
#include <string>

/**
 * @namespace string
 * @brief 重复的子字符串
 */

namespace algo {
namespace string {

/**
 * @brief 重复的子字符串
 *
 * @details
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 * @par 示例
 *
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 *
 * 输入: s = "aba"
 * 输出: false
 *
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 *
 * @see [leetcode-459](https://leetcode.cn/problems/repeated-substring-pattern/)
 */

class RepeatedSubstring {
 public:
  bool repeatedSubstringPattern1(std::string str) { return (str + str).find(str, 1) != str.size(); }

  /**
   * @ingroup kmp
   */
  bool repeatedSubstringPattern2(std::string str) {
    size_t len = str.length();
    size_t next[len];
    next[0] = 0;

    auto func = [&next](const std::string& s) {
      for (size_t i = 1, j = 0; i < s.length(); i++) {
        while (j > 0 && s[i] != s[j]) {
          j = next[j - 1];
        }

        if (s[i] == s[j]) {
          j++;
        }

        next[i] = j;
      }
    };

    func(str);

    return next[len - 1] != 0 && (len % (len - next[len - 1]) == 0);
  }
};
}  // namespace string
}  // namespace algo