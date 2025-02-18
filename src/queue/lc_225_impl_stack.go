package queue

/**
 * @brief 用队列实现栈
 *
 * @details
 *请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 实现 MyStack 类：
 *
 * @code
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 * @endcode
 *
 * 注意：
 * 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
 * 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 ,
 * 只要是标准的队列操作即可。
 *
 * @par 示例
 *
 * 输入：
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 2, 2, false]
 * 解释：
 * @code
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // 返回 2
 * myStack.pop(); // 返回 2
 * myStack.empty(); // 返回 False
 * @endcode
 *
 * @see [leetcode-225](https://leetcode.cn/problems/implement-stack-using-queues/)
 */

type MyQueue []int

func (q *MyQueue) push(x int) {
	*q = append(*q, x)
}

func (q *MyQueue) pop() {
	*q = (*q)[1:]
}

func (q *MyQueue) peek() int {
	return (*q)[0]
}

func (q *MyQueue) empty() bool {
	return len(*q) == 0
}

type MyStack struct {
	queue1 *MyQueue
	queue2 *MyQueue
}

func Constructor() MyStack {
	return MyStack{&MyQueue{}, &MyQueue{}}
}

func (s *MyStack) Push(x int) {
	s.queue2.push(x)
	s.move()
}

func (s *MyStack) Pop() int {
	var res = s.queue1.peek()
	s.queue1.pop()
	return res
}

func (s *MyStack) Top() int {
	return s.queue1.peek()
}

func (s *MyStack) Empty() bool {
	return s.queue1.empty()
}

func (s *MyStack) move() {
	if s.queue1.empty() {
		s.queue1, s.queue2 = s.queue2, s.queue1
	} else {
		var res int = s.queue1.peek()
		s.queue1.pop()
		s.queue2.push(res)
		s.move()
	}
}
