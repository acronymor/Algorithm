package string

/**
 * @brief 反转字符串中的单词
 *
 * @details
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 * @par 示例
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 *
 * @see [leetcode-151](https://leetcode.cn/problems/reverse-words-in-a-string/)
 */

func reverseWords(s string) string {
	var slow int = 0
	var fast int = 0

	st := []byte(s)

	for i := 0; i < len(st); i++ {
		if st[i] != ' ' {
			break
		}
		fast++
	}

	for ; fast < len(st); fast++ {
		if fast > 0 && st[fast-1] == st[fast] && st[fast] == ' ' {
			continue
		}
		st[slow] = st[fast]
		slow++
	}

	if slow > 0 && st[slow-1] == ' ' {
		st = st[:slow-1]
	} else {
		st = st[:slow]
	}

	reverse := func(start, end int) {
		for i, j := start, end; i < j; {
			st[i], st[j] = st[j], st[i]

			i++
			j--
		}
	}

	reverse(0, len(st)-1)

	var i int = 0
	for j := 0; j < len(st); j++ {
		if st[j] == ' ' {
			reverse(i, j-1)
			i = j + 1
		}
	}

	reverse(i, len(st)-1)

	return string(st)
}
