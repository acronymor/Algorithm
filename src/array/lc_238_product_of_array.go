package array

/**
 * @brief 除自身以外数组的乘积
 *
 * @details
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 * 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
 *
 * @par 示例
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 *
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 *
 * @see [leetcode-238](https://leetcode.cn/problems/product-of-array-except-self/)
 */

func productExceptSelf(nums []int) []int {
	var left []int = make([]int, len(nums))
	var right []int = make([]int, len(nums))

	left[0] = 1
	for i := 1; i < len(nums); i++ {
		left[i] = left[i-1] * nums[i-1]
	}

	right[len(nums)-1] = 1
	for j := len(nums) - 2; j >= 0; j-- {
		right[j] = right[j+1] * nums[j+1]
	}

	var res []int = make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		res[i] = left[i] * right[i]
	}

	return res
}
