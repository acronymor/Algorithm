#include <iostream>
#include <string>
#include <unordered_set>

/**
 * @namespace string
 * @brief 最长回文子串
 */

namespace algo {
namespace string {
/**
 * @brief 最长回文子串
 *
 * @details
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 * @par 示例
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 * @see [leetcode-5](https://leetcode.cn/problems/longest-palindromic-substring/)
 */

class LongestPalindrome {
 public:
  /**
   * @ingroup dynamic-programming
   */
  std::string longestPalindrome1(std::string s) {
    bool dp[s.length()][s.length()];

    for (size_t i = 0; i < s.length(); i++) {
      dp[i][i] = true;
    }

    size_t left = 0;
    size_t len = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
      for (int j = i + 1; j < s.length(); j++) {
        if (s[i] != s[j]) {
          dp[i][j] = false;
        } else {
          // (j-1)-(i+1)+1 < 2
          if (j - i < 3) {
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        if (dp[i][j] == true && len < j - i + 1) {
          left = i;
          len = j - i + 1;
        }
      }
    }

    return s.substr(left, len);
  }

  std::string longestPalindrome2(std::string s) {
    int start = 0, len = 1;
    for (size_t i = 0; i < s.length(); i++) {
      int left = i, right = i;
      while (left >= 0 && s[left] == s[i]) {
        left--;
      }

      while (right < s.length() && s[right] == s[i]) {
        right++;
      }

      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
      }

      int new_len = (right - 1) - (left + 1) + 1;
      if (len < new_len) {
        start = left + 1;
        len = new_len;
      }
    }
    return s.substr(start, len);
  }
};
}  // namespace string
};  // namespace algo