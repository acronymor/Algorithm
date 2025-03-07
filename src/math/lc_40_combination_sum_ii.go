package math

import "sort"

/**
 * @brief 组合总和 II
 *
 * @details
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 注意：解集不能包含重复的组合。
 *
 * @par 示例
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出: [[1,1,6], [1,2,5], [1,7], [2,6]]
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出: [[1,2,2], [5]]
 *
 * @see [leetcode-40](https://leetcode.cn/problems/combination-sum-ii/)
 */

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)

	var res [][]int = make([][]int, 0)
	var ans []int = make([]int, 0, len(candidates))

	var backtrace func(idx int, sum int)

	backtrace = func(idx int, sum int) {
		if sum > target {
			return
		}

		if sum == target {
			tmp := make([]int, len(ans))
			copy(tmp, ans)
			res = append(res, tmp)
			return
		}

		for i := idx; i < len(candidates); i++ {
			if sum+candidates[i] > target {
				break
			}

			if i != idx && candidates[i] == candidates[i-1] {
				continue
			}

			ans = append(ans, candidates[i])
			backtrace(i+1, sum+candidates[i])
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(0, 0)

	return res
}
