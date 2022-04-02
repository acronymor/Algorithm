#include <iostream>
#include <stack>

/**
 * @namespace stack
 * @brief 用栈实现队列
 */

namespace algo {
namespace stack {

/**
 * @brief 用栈实现队列
 *
 * @details
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
 *
 * 实现 MyQueue 类：
 * @code
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 * @endcode
 *
 * 说明：
 * 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 *
 * @par 示例
 *
 * 输入：
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 1, 1, false]
 *
 * @see [leetcode-232](https://leetcode.cn/problems/implement-queue-using-stacks/)
 */

class MyQueue {
 public:
  /**
   * @ingroup stack
   */
  MyQueue() {}

  void push(int x) { stack1_.push(x); }

  int pop() {
    int res = peek();
    stack2_.pop();
    return res;
  }

  int peek() {
    int res = -1;
    if (stack2_.empty()) {
      while (!stack1_.empty()) {
        int tmp = stack1_.top();
        stack2_.push(tmp);
        stack1_.pop();
      }
    }

    res = stack2_.top();
    return res;
  }

  bool empty() { return stack1_.empty() && stack2_.empty(); }

 private:
  std::stack<int> stack1_;
  std::stack<int> stack2_;
};
}  // namespace stack
};  // namespace algo