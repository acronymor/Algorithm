package math

/**
 * @brief 子集
 *
 * @details
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 * @see [leetcode-78](https://leetcode.cn/problems/subsets/)
 */

func subsets(nums []int) [][]int {
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
			ans = append(ans, nums[i])
			backtrace(i + 1)
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(0)

	return res
}
