#include <iostream>
#include <vector>
#include <cstdint>

/**
 * @namespace string
 * @brief 不同的子序列
 */

namespace algo {
namespace string {

/**
 * @brief 不同的子序列
 *
 * @details
 * 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
 * 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是
 * "ABCDE" 的一个子序列，而 "AEC" 不是）
 *
 * @par 示例
 *
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 *
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 *
 * @see [leetcode-115](https://leetcode.cn/problems/distinct-subsequences)
 */

class NumDistinct {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve(const std::string& s, const std::string& t) {
    std::vector<std::vector<uint64_t>> dp(s.size() + 1, std::vector<uint64_t>(t.size() + 1, 0));

    for (int i = 0; i <= s.size(); i++) {
      dp[i][0] = 1;
    }
    for (int j = 1; j <= t.size(); j++) {
      dp[0][j] = 0;
    }

    for (int i = 1; i <= s.size(); i++) {
      for (int j = 1; j <= t.size(); j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[s.size()][t.size()];
  }
};
}  // namespace string
}  // namespace algo