#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

/**
 * @namespace string
 * @brief 有效的括号
 */

namespace algo {
namespace string {

/**
 * @brief 有效的括号
 *
 * @details
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 * @par 示例
 *
 * 输入：s = "()"
 * 输出：true
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 * @see [leetcode-20](https://leetcode.cn/problems/valid-parentheses/)
 */

class IsValid {
 public:
  /**
   * @ingroup stack
   */
  bool isValid1(std::string s) {
    std::unordered_map<char, char> maps;
    maps.emplace(')', '(');
    maps.emplace(']', '[');
    maps.emplace('}', '{');

    std::stack<char> stacks;

    for (size_t i = 0; i < s.length(); i++) {
      auto itr = maps.find(s[i]);
      if (itr != maps.end() && !stacks.empty() && stacks.top() == itr->second) {
        stacks.pop();
      } else {
        stacks.push(s[i]);
      }
    }

    return stacks.empty();
  }

  /**
   * @ingroup stack
   */
  bool isValid2(std::string s) {
    std::stack<char> stacks;

    for (size_t i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        stacks.push(')');
      } else if (s[i] == '[') {
        stacks.push(']');
      } else if (s[i] == '{') {
        stacks.push('}');
      } else if (stacks.empty() || stacks.top() != s[i]) {
        return false;
      } else {
        stacks.pop();
      }
    }

    return stacks.empty();
  }
};
}  // namespace string
};  // namespace algo