package string

/**
 * @brief 分割回文串
 *
 * @details
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 回文串 是正着读和反着读都一样的字符串。
 *
 * @par 示例
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 * @see [leetcode-131](https://leetcode.cn/problems/palindrome-partitioning/)
 */

func partition(s string) [][]string {
	var check func(b []byte) bool

	check = func(b []byte) bool {
		for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
			if b[i] != b[j] {
				return false
			}
		}
		return true
	}

	var arr []byte = ([]byte)(s)
	var res [][]string = make([][]string, 0)
	var ans []string = make([]string, 0, len(arr))

	var backtrace func(idx int)
	backtrace = func(idx int) {
		if idx == len(arr) {
			var tmp []string = make([]string, len(ans))
			copy(tmp, ans)
			res = append(res, tmp)
			return
		}

		for i := idx; i < len(arr); i++ {
			b := arr[idx : i+1]
			if check(b) {
				ans = append(ans, string(b))
				backtrace(i + 1)
				ans = ans[:len(ans)-1]
			}
		}
	}

	backtrace(0)

	return res
}
