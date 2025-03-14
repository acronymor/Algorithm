package array

/**
 * @brief 最大子数组和
 *
 * @details
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 *
 * @par 示例
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 * 输入：nums = [1]
 * 输出：1
 *
 * @see [leetcode-53](https://leetcode.cn/problems/maximum-subarray/)
 */

func maxSubArray1(nums []int) int {
	var dp []int = make([]int, len(nums))
	dp[0] = nums[0]
	var res = dp[0]

	for i := 1; i < len(nums); i++ {
		dp[i] = max(nums[i], dp[i-1]+nums[i])
		if dp[i] > res {
			res = dp[i]
		}
	}
	return res
}

func maxSubArray2(nums []int) int {
	var maxValue int = nums[0]
	var res int = 0

	for i := 0; i < len(nums); i++ {
		res += nums[i]
		if res > maxValue {
			maxValue = res
		}

		if res < 0 {
			res = 0
		}
	}

	return maxValue
}
