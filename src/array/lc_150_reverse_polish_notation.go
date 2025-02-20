package array

import "strconv"

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

type Stack []int

func (s *Stack) push(x int) {
	*s = append(*s, x)
}

func (s *Stack) pop() {
	*s = (*s)[:len(*s)-1]
}

func (s *Stack) top() int {
	return (*s)[len(*s)-1]
}

func (s *Stack) empty() bool {
	return len(*s) == 0
}

func evalRPN(tokens []string) int {
	var table map[string]bool = map[string]bool{
		"+": true,
		"-": true,
		"*": true,
		"/": true,
	}

	stack := Stack{}

	for _, token := range tokens {
		if _, ok := table[token]; !ok {
			num, _ := strconv.Atoi(token)
			stack.push(num)
		} else {
			a := stack.top()
			stack.pop()
			b := stack.top()
			stack.pop()

			var tmp int = 0
			switch token {
			case "+":
				tmp = b + a
				break
			case "-":
				tmp = b - a
				break
			case "*":
				tmp = b * a
				break
			case "/":
				tmp = b / a
				break
			}
			stack.push(tmp)
		}
	}

	return stack.top()
}
