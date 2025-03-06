package array

/**
 * @brief 电话号码的字母组合
 *
 * @details
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * @par 示例
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 * 输入：digits = ""
 * 输出：[]
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 */

func letterCombinations(digits string) []string {
	ans, res := make([]byte, 0), make([]string, 0)
	if len(digits) == 0 {
		return res
	}

	var arr []string = []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	var backtrace func(idx int)

	backtrace = func(idx int) {
		if len(ans) == len(digits) {
			res = append(res, string(ans))
			return
		}

		letter := arr[digits[idx]-'0']

		for j := 0; j < len(letter); j++ {
			ans = append(ans, letter[j])
			backtrace(idx + 1)
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(0)

	return res
}
