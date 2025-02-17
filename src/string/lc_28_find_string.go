package string

import "strings"

/**
 * @brief 找出字符串中第一个匹配项的下标
 *
 * @details
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 *
 * @par 示例
 *
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 *
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 *
 * @see [leetcode-28](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)
 */

func strStr1(haystack string, needle string) int {
	return strings.Index(haystack, needle)
}

func strStr2(haystack string, needle string) int {
	toNext := func(s string) []int {
		var next []int = make([]int, len(s))
		j := 0
		for i := 1; i < len(s); i++ {
			for j > 0 && s[j] != s[i] {
				j = next[j-1]
			}
			if s[j] == s[i] {
				j++
			}

			next[i] = j
		}
		return next
	}

	var next []int = toNext(needle)
	for i, j := 0, 0; i < len(haystack); i++ {
		for j > 0 && haystack[i] != needle[j] {
			j = next[j-1]
		}
		if haystack[i] == needle[j] {
			j++
		}

		if j == len(needle) {
			return i - j + 1
		}
	}

	return -1
}
