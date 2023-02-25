#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief string
 */

namespace algo {
namespace string {

/**
 * @brief 不同的子序列
 *
 * @details
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 * @par 示例
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 * @see [leetcode-72](https://leetcode.cn/problems/edit-distance/)
 */

class MinDistinct {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve(const std::string& s, const std::string& t) {
    std::vector<std::vector<uint64_t>> dp(s.size() + 1, std::vector<uint64_t>(t.size() + 1, 0));

    for (int i = 0; i <= s.size(); i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= t.size(); j++) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= s.size(); i++) {
      for (int j = 1; j <= t.size(); j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
      }
    }

    return dp[s.size()][t.size()];
  }
};
}  // namespace string
}  // namespace algo