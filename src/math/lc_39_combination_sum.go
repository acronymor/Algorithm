package math

import "sort"

/**
 * @brief 组合总和
 *
 * @details
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
 * 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。 candidates 中的 同一个 数字可以 无限制重复被选取
 * 。如果至少一个数字的被选数量不同，则两种组合是不同的。 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 *
 * @par 示例
 *
 * 输入：candidates = [2,3,6,7], target = 7
 * 输出：[[2,2,3],[7]]
 *
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * 输入: candidates = [2], target = 1
 * 输出: []
 *
 * @see [leetcode-39](https://leetcode.cn/problems/combination-sum/)
 */

func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var res [][]int = make([][]int, 0)
	var ans []int = make([]int, 0)
	var backtrace func(idx int, sum int)

	backtrace = func(idx int, sum int) {
		if sum > target {
			return
		}

		if sum == target {
			tmp := make([]int, len(ans))
			copy(tmp, ans)
			res = append(res, tmp)
		}

		for i := idx; i < len(candidates); i++ {
			if sum+candidates[i] > target {
				break
			}

			ans = append(ans, candidates[i])
			backtrace(i, sum+candidates[i])
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(0, 0)

	return res
}
