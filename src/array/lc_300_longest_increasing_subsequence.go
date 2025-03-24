package array

/**
 * @brief 最长递增子序列
 *
 * @details
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
 * 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 *
 * @par 示例
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 * @see [leetcode-300](https://leetcode.cn/problems/longest-increasing-subsequence/)
 */

func lengthOfLIS(nums []int) int {
	var dp []int = make([]int, len(nums))
	for idx := range dp {
		dp[idx] = 1
	}

	var maxResult int = dp[0]
	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		if dp[i] > maxResult {
			maxResult = dp[i]
		}
	}

	return maxResult
}
