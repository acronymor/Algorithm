#include <iostream>
#include <stack>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief 最长有效括号
 */

namespace algo {
namespace string {

/**
 * @brief 最长有效括号
 *
 * @details
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 * @par 示例
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 * 输入：s = ""
 * 输出：0
 *
 * @see [leetcode-32](https://leetcode.cn/problems/longest-valid-parentheses/)
 */

class LongestValidParentheses {
 public:
  int longestValidParentheses1(std::string s) {
    int res = 0;

    std::stack<int> stacks;
    stacks.push(-1);

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        stacks.push(i);
      } else {
        stacks.pop();
        if (stacks.empty()) {
          stacks.push(i);
        } else {
          res = std::max(res, i - stacks.top());
        }
      }
    }

    return res;
  }

  int longestValidParentheses2(std::string s) {
    int res = 0;
    std::vector<int> dp(s.size(), 0);

    for (int i = 1; i < s.length(); i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          int tmp = i >= 2 ? dp[i - 2] : 0;
          dp[i] = tmp + 2;
        } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          int tmp = i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0;
          dp[i] = dp[i - 1] + tmp + 2;
        }
      }

      res = std::max(res, dp[i]);
    }

    return res;
  }
};
}  // namespace string
}  // namespace algo