#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 判断子序列
 */

namespace algo {
namespace string {

/**
 * @brief 判断子序列
 *
 * @details
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
 * （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 *
 * @par 示例
 *
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 *
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 *
 * @see [leetcode-1143](https://leetcode.cn/problems/is-subsequence)
 */

class IsSubsequence {
 public:
  /**
   * @ingroup dynamic-programming
   */
  bool solve(const std::string& s1, const std::string& s2) {
    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }

    return dp[s1.size()][s2.size()] == s1.size();
  }
};
}  // namespace string
}  // namespace algo