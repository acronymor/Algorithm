#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief 两个字符串的删除操作
 */

namespace algo {
namespace string {

/**
 * @brief 两个字符串的删除操作
 *
 * @details
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
 * 每步 可以删除任意一个字符串中的一个字符。
 *
 * @par 示例
 *
 * 输入: word1 = "sea", word2 = "eat"
 * 输出: 2
 * 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
 *
 * 输入：word1 = "leetcode", word2 = "etco"
 * 输出：4
 *
 * @see [leetcode-583](https://leetcode.cn/problems/delete-operation-for-two-strings/)
 */

class MinDistance {
 public:
  int solve(const std::string& word1, const std::string& word2) {
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return (word1.size() + word2.size()) - (dp[word1.size()][word2.size()] * 2);
  }
};
}  // namespace string
}  // namespace algo