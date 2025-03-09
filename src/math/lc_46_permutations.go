package math

/**
 * @brief 全排列
 *
 * @details
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 * @see [leetcode-46](https://leetcode.cn/problems/permutations/)
 */

func permute(nums []int) [][]int {
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
