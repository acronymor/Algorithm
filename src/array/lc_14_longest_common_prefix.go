package array

import "strings"

/**
 * @brief 最长公共前缀
 *
 * @details
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * @par 示例
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 *
 * @see [leetcode-14](https://leetcode.cn/problems/longest-common-prefix/)
 */

func longestCommonPrefix(strs []string) string {
	letter := strs[0]

	var res string = ""

	for i := 0; i < len(letter); i++ {
		prefix := letter[:i+1]
		flag := true
		for j := 0; j < len(strs); j++ {
			flag = flag && strings.HasPrefix(strs[j], prefix)
		}

		if !flag {
			return res
		}
		res = prefix
	}

	return res
}
