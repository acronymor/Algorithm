#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * @namespace array
 * @brief 单词拆分
 */

namespace algo {
namespace array {

/**
 * @brief 单词拆分
 *
 * @details
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 *
 * @par 示例
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 *
 * @see [leetcode-139](https://leetcode.cn/problems/word-break/)
 */

class WordBreak {
 public:
  bool solve(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        std::string word = s.substr(j, i - j);
        if (wordSet.find(word) != wordSet.end() && dp[j]) {
          dp[i] = true;
        }
      }
    }
    return dp[s.size()];
  }
};
}  // namespace array
}  // namespace algo