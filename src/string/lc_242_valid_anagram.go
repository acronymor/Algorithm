package string

/**
 * @brief 有效的字母异位词
 *
 * @details
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 *
 * @par 示例
 *
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 *
 * 输入: s = "rat", t = "car"
 * 输出: false
 *
 * @see [leetcode-242](https://leetcode.cn/problems/valid-anagram/)
 */

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	var table map[byte]int = make(map[byte]int, len(s))

	for i := 0; i < len(s); i++ {
		table[s[i]]++
	}

	for i := 0; i < len(t); i++ {
		table[t[i]]--
	}

	for _, value := range table {
		if value != 0 {
			return false
		}
	}

	return true
}
