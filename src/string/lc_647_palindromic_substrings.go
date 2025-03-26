package string

/**
 * @brief 回文子串
 *
 * @details
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 *
 * @par 示例
 *
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 *
 * @see [leetcode-647](https://leetcode.cn/problems/palindromic-substrings/)
 */

func countSubstrings1(s string) int {
	var res int = 0
	var dp [][]bool = make([][]bool, len(s))

	for i := 0; i < len(s); i++ {
		dp[i] = make([]bool, len(s))
	}

	for i := 0; i < len(s); i++ {
		for j := 0; j <= i; j++ {
			if s[i] == s[j] && (j-i <= 1 || dp[i+1][j-1]) {
				dp[i][j] = true
				res++
			}
		}
	}

	return res
}

func countSubstrings2(s string) int {
	var extend func(s string, left int, right int) int

	extend = func(s string, i int, j int) int {
		var ans = 0

		for i >= 0 && j < len(s) && s[i] == s[j] {
			i--
			j++
			ans++
		}

		return ans
	}

	var res int = 0
	for i := 0; i < len(s); i++ {
		res += extend(s, i, i)
		res += extend(s, i, i+1)
	}

	return res
}
