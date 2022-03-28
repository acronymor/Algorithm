#include <iostream>
#include <string>

/**
 * @namespace string
 * @brief 找出字符串中第一个匹配项的下标
 */

namespace algo {
namespace string {

/**
 * @brief 找出字符串中第一个匹配项的下标
 *
 * @details
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 *
 * @par 示例
 *
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 *
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 *
 * @see [leetcode-28](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)
 */

class StrStr {
 public:
  int strStr1(std::string haystack, std::string needle) {
    int pos = haystack.find(needle);
    return pos;
  }

  /**
   * @ingroup kmp
   */
  int strStr2(std::string haystack, std::string needle) {
    size_t next[needle.size()];
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
    func(needle);

    for (size_t i = 0, j = 0; i < haystack.length(); i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }

      if (haystack[i] == needle[j]) {
        j++;
      }

      if (j == needle.size()) {
        return i - needle.size() + 1;
      }
    }

    return -1;
  }

  /**
   * @ingroup kmp
   */
  int strStr3(std::string haystack, std::string needle) {
    int next[needle.size()];
    next[0] = -1;
    auto func = [&next](const std::string& s) {
      for (int i = 1, j = -1; i < s.length(); i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
          j = next[j];
        }
        if (s[i] == s[j + 1]) {
          j++;
        }
        next[i] = j;
      }
    };
    func(needle);

    for (int i = 0, j = -1; i < haystack.length(); i++) {
      while (j >= 0 && haystack[i] != needle[j + 1]) {
        j = next[j];
      }

      if (haystack[i] == needle[j + 1]) {
        j++;
      }

      if (j == needle.size() - 1) {
        return i - needle.size() + 1;
      }
    }

    return -1;
  }
};
}  // namespace string
}  // namespace algo