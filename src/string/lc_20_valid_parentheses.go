package string

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

type Stack []byte

func (s *Stack) push(x byte) {
	*s = append((*s), x)
}

func (s *Stack) pop() {
	*s = (*s)[:len(*s)-1]
}

func (s *Stack) top() byte {
	return (*s)[len(*s)-1]
}

func (s *Stack) empty() bool {
	return len(*s) == 0
}

func isValid(s string) bool {
	ss := []byte(s)

	var table map[byte]byte = map[byte]byte{
		'}': '{',
		']': '[',
		')': '(',
	}

	var stack Stack = Stack{}

	for _, b := range ss {
		if tmp, ok := table[b]; !ok {
			stack.push(b)
		} else {
			if stack.empty() {
				return false
			}

			if ch := stack.top(); ch != tmp {
				return false
			}
			stack.pop()
		}
	}

	return stack.empty()
}
