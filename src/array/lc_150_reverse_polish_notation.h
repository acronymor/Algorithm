#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

/**
 * @namespace array
 * @brief 逆波兰表达式求值
 */

namespace algo {
namespace array {

/**
 * @brief 逆波兰表达式求值
 *
 * @details
 * 根据 逆波兰表示法，求表达式的值。
 * 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 注意 两个整数之间的除法只保留整数部分。
 * 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 *
 * @par 示例
 *
 * 输入：tokens = ["2","1","+","3","*"]
 * 输出：9
 * 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 *
 * 输入：tokens = ["4","13","5","/","+"]
 * 输出：6
 * 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
 *
 * 输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * 输出：22
 * 解释：该算式转化为常见的中缀算术表达式为：
 * @code
 *   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * @endcode
 *
 * @see [leetcode-150](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)
 */

class EvalRPN {
 public:
  /**
   * @ingroup stack
   */
  int evalRPN(std::vector<std::string>& tokens) {
    std::unordered_set<std::string> sets = {"+", "-", "*", "/"};
    std::stack<long long> stacks;
    for (const std::string& s : tokens) {
      if (sets.contains(s)) {
        long long n1 = stacks.top();
        stacks.pop();
        long long n2 = stacks.top();
        stacks.pop();
        if (s == "+") {
          stacks.push(n2 + n1);
        }
        if (s == "-") {
          stacks.push(n2 - n1);
        }
        if (s == "*") {
          stacks.push(n2 * n1);
        }
        if (s == "/") {
          stacks.push(n2 / n1);
        }
      } else {
        stacks.push(std::stoll(s));
      }
    }
    int res = stacks.top();
    stacks.pop();

    return res;
  }
};

}  // namespace array
}  // namespace algo