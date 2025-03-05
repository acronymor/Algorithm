package math

/**
 * @brief 组合总和 III
 *
 * @details
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 * 只使用数字1到9
 * 每个数字 最多使用一次
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 *
 * @par 示例
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 *
 * @see [leetcode-216](https://leetcode.cn/problems/combination-sum-iii/)
 */

func combinationSum3(n int, k int) [][]int {
	ans, res := make([]int, 0, k), make([][]int, 0)

	var maxVal int = 9

	var backtrace func(idx int, sum int)

	backtrace = func(idx int, sum int) {
		if sum < 0 {
			return
		}

		if len(ans) == k && sum == 0 {
			tmp := make([]int, k)
			copy(tmp, ans)
			res = append(res, tmp)
			return
		}

		for i := idx; i <= maxVal; i++ {
			if sum-i < 0 || maxVal-i+1 < k-len(ans) {
				break
			}

			ans = append(ans, i)
			backtrace(i+1, sum-i)
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(1, n)

	return res
}
