package array

/**
 * @brief 最长连续递增子序列
 *
 * @details
 * 给你一个整数数组 nums ，找到其中最长连续递增子序列的长度。
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列
 * [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 *
 * @par 示例
 *
 * 输入：nums = [1,3,5,4,7]
 * 输出：3
 * 解释：最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
 *
 * 输入：nums = [2,2,2,2,2]
 * 输出：1
 * 解释：最长连续递增序列是 [2], 长度为1。
 *
 * @see [leetcode-674](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)
 */

func findLengthOfLCIS(nums []int) int {
	var dp []int = make([]int, len(nums))

	for idx := range nums {
		dp[idx] = 1
	}

	var maxResult int = dp[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			dp[i] = dp[i-1] + 1
		}

		if maxResult < dp[i] {
			maxResult = dp[i]
		}
	}

	return maxResult
}
