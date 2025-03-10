package array

/**
 * @brief 非递减子序列
 *
 * @details
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 *
 * @par 示例
 *
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 *
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 *
 * @see [leetcode-491](https://leetcode.cn/problems/non-decreasing-subsequences/)
 */
func findSubsequences(nums []int) [][]int {
	var res [][]int = make([][]int, 0)
	var ans []int = make([]int, 0, len(nums))

	var backtrace func(idx int)
	backtrace = func(idx int) {
		if len(ans) > 1 {
			var tmp []int = make([]int, len(ans))
			copy(tmp, ans)
			res = append(res, tmp)
		}

		var used map[int]bool = make(map[int]bool, len(nums))
		for i := idx; i < len(nums); i++ {
			if used[nums[i]] || (len(ans) != 0 && nums[i] < ans[len(ans)-1]) {
				continue
			}

			used[nums[i]] = true
			ans = append(ans, nums[i])
			backtrace(i + 1)
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(0)

	return res
}
