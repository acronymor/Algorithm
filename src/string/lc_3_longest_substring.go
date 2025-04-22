package string

/**
 * @brief 无重复字符的最长子串
 *
 * @details
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 *
 * @par 示例
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 *
 * @see [leetcode-3](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)
 */

func lengthOfLongestSubstring(s string) int {
	var table map[byte]int = make(map[byte]int, len(s))

	i, j := 0, 0
	var res int = 0

	for ; j < len(s); j++ {
		for {
			if _, ok := table[s[j]]; !ok {
				break
			}
			delete(table, s[i])
			i++
		}

		table[s[j]] = j
		res = max(res, j-i+1)
	}

	return res
}
