package math

import "strconv"

/**
 * @brief 单调递增的数字
 *
 * @details
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 *
 * @par 示例
 *
 * 输入: n = 10
 * 输出: 9
 *
 * 输入: n = 1234
 * 输出: 1234
 *
 * @see [leetcode-738](https://leetcode.cn/problems/monotone-increasing-digits/)
 */

func monotoneIncreasingDigits(n int) int {
	var m []byte = []byte(strconv.Itoa(n))

	var pos = len(m)
	for i := len(m) - 1; i > 0; i-- {
		if m[i-1] > m[i] {
			pos = i
			m[i-1] -= 1
		}
	}

	for i := pos; i < len(m); i++ {
		m[i] = '9'
	}

	res, _ := strconv.Atoi(string(m))
	return res
}
