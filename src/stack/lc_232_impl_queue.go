package stack

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

type MyStack []int

func (s *MyStack) push(x int) {
	*s = append(*s, x)
}

func (s *MyStack) pop() {
	*s = (*s)[:len(*s)-1]
}

func (s *MyStack) peek() int {
	return (*s)[len(*s)-1]
}

func (s *MyStack) empty() bool {
	return len(*s) == 0
}

type MyQueue struct {
	stack1 *MyStack
	stack2 *MyStack
}

func Constructor() MyQueue {
	return MyQueue{&MyStack{}, &MyStack{}}
}

func (q *MyQueue) Push(x int) {
	q.stack1.push(x)
}

func (q *MyQueue) Pop() int {
	q.fill()
	var res int = q.stack2.peek()
	q.stack2.pop()
	return res
}

func (q *MyQueue) Peek() int {
	q.fill()
	return q.stack2.peek()
}

func (q *MyQueue) Empty() bool {
	return q.stack1.empty() && q.stack2.empty()
}

func (q *MyQueue) fill() {
	if q.stack2.empty() {
		for !q.stack1.empty() {
			var res = q.stack1.peek()
			q.stack1.pop()
			q.stack2.push(res)
		}
	}
}
