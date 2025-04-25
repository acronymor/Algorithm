package string

import (
	"strings"
)

/**
 * @brief 单词规律
 *
 * @details
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
 *
 * @par 示例
 *
 * 输入: pattern = "abba", s = "dog cat cat dog"
 * 输出: true
 *
 * 输入:pattern = "abba", s = "dog cat cat fish"
 * 输出: false
 *
 * @see [leetcode-290](https://leetcode.cn/problems/word-pattern/)
 */

func wordPattern(pattern string, s string) bool {
	var ss []string = strings.Split(s, " ")
	if len(pattern) != len(ss) {
		return false
	}

	var table1 map[byte]string = make(map[byte]string, len(pattern))
	var table2 map[string]byte = make(map[string]byte, len(ss))

	for i := 0; i < len(pattern); i++ {
		word, ok1 := table1[pattern[i]]
		ch, ok2 := table2[ss[i]]

		if ok1 != ok2 {
			return false
		}

		if (ok1 && ok2) && (word != ss[i] || ch != pattern[i]) {
			return false
		}

		table1[pattern[i]] = ss[i]
		table2[ss[i]] = pattern[i]
	}

	return true
}
