package math

import "sort"

/**
 * @brief 子集 II
 *
 * @details
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 * @see [leetcode-90](https://leetcode.cn/problems/subsets-ii/)
 */

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)

	var res [][]int = make([][]int, 0)
	var ans []int = make([]int, 0, len(nums))

	var backtrace func(idx int)

	backtrace = func(idx int) {
		var tmp []int = make([]int, len(ans))
		copy(tmp, ans)
		res = append(res, tmp)

		if idx == len(nums) {
			return
		}

		for i := idx; i < len(nums); i++ {
			if i != idx && nums[i-1] == nums[i] {
				continue
			}

			ans = append(ans, nums[i])
			backtrace(i + 1)
			ans = ans[:len(ans)-1]
		}

	}

	backtrace(0)

	return res
}
