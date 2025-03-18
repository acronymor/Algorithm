package math

/**
 * @brief 组合总和 IV
 *
 * @details
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target
 * 的元素组合的个数。 题目数据保证答案符合 32 位整数范围。
 *
 * @par 示例
 *
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 *
 * 输入：nums = [9], target = 3
 * 输出：0
 *
 * @see [leetcode-377](https://leetcode.cn/problems/combination-sum-iv/)
 */

func combinationSum4(nums []int, target int) int {
	var dp []int = make([]int, target+1)
	dp[0] = 1
	for j := 0; j <= target; j++ {
		for i := 0; i < len(nums); i++ {
			if nums[i] > j {
				dp[j] = dp[j]
			} else {
				dp[j] += dp[j-nums[i]]
			}
		}
	}

	return dp[target]
}
