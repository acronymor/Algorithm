package math

import "sort"

/**
 * @brief 全排列
 *
 * @details
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 * @par 示例
 *
 * 输入：nums = [1,1,2]
 * 输出：[[1,1,2],[1,2,1],[2,1,1]]
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * @see [leetcode-47](https://leetcode.cn/problems/permutations-ii/)
 */

func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)

	var res [][]int = make([][]int, 0)
	var ans []int = make([]int, 0, len(nums))
	var used []bool = make([]bool, len(nums))

	var backtrace func(idx int)

	backtrace = func(idx int) {
		if idx == len(nums) {
			var tmp []int = make([]int, len(ans))
			copy(tmp, ans)
			res = append(res, tmp)
		}

		for i := 0; i < len(nums); i++ {
			if i > 0 && nums[i-1] == nums[i] && used[i-1] == false {
				continue
			}

			if used[i] {
				continue
			}

			used[i] = true
			ans = append(ans, nums[i])
			backtrace(idx + 1)
			ans = ans[:len(ans)-1]
			used[i] = false
		}

	}

	backtrace(0)

	return res
}
