package string

/**
 * @brief 最长回文子串
 *
 * @details
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 * @par 示例
 *
 * 示例 1：
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 * @see [leetcode-5](https://leetcode.cn/problems/longest-palindromic-substring/)
 */

func longestPalindrome(s string) string {
	var to = func(i, j int) (int, int) {
		for {
			if i < 0 || j >= len(s) {
				break
			}

			if s[i] != s[j] {
				break
			}
			i--
			j++
		}

		return i + 1, j - 1
	}

	left, right := 0, 0
	for i := 0; i < len(s); i++ {
		a, b := to(i, i)
		c, d := to(i, i+1)

		if b-a > right-left {
			left, right = a, b
		}

		if d-c > right-left {
			left, right = c, d
		}
	}

	return s[left : right+1]
}
