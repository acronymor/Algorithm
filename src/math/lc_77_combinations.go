package math

/**
 * @brief 组合
 *
 * @details
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 你可以按 任何顺序 返回答案。
 *
 * @par 示例
 *
 * 输入：n = 4, k = 2
 * 输出： [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 * @see [leetcode-77](https://leetcode.cn/problems/combinations/)
 */

func combine(n int, k int) [][]int {
	var res [][]int
	var ans []int = make([]int, 0, k)

	var backtrace func(i int)

	backtrace = func(idx int) {
		if len(ans) == k {
			tmp := make([]int, k)
			copy(tmp, ans)
			res = append(res, tmp)
			return
		}

		for i := idx; i <= n; i++ {
			if n-i+1 < k-len(ans) {
				break
			}

			ans = append(ans, i)
			backtrace(i + 1)
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(1)

	return res
}
