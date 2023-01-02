#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief 分割回文串
 */

namespace algo {
namespace string {

/**
 * @brief 分割回文串
 *
 * @details
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 回文串 是正着读和反着读都一样的字符串。
 *
 * @par 示例
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 * @see [leetcode-131](https://leetcode.cn/problems/palindrome-partitioning/)
 */

class PalindromeSubString {
 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::string> v;
    std::vector<std::vector<std::string>> res;
    backtracking(s, res, v, 0);
    return res;
  }

 private:
  bool isPalindrome(const std::string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

  void backtracking(const std::string& s, std::vector<std::vector<std::string>>& res, std::vector<std::string>& v,
                    int start) {
    if (start == s.length()) {
      res.push_back(v);
      return;
    }

    for (int i = start; i < s.length(); i++) {
      if (!isPalindrome(s, start, i)) {
        continue;
      };
      v.push_back(s.substr(start, i - start + 1));
      backtracking(s, res, v, i + 1);
      v.pop_back();
    }
  }
};
}  // namespace string
}  // namespace algo