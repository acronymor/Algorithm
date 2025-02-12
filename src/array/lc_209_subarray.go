package array

import "math"

/**
 * @brief 长度最小的子数组
 *
 * @details
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
 * 并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 * @par 示例
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 * @see [leetcode-209](https://leetcode.cn/problems/minimum-size-subarray-sum/)
 */

func minSubArrayLen(target int, nums []int) int {
	var res int = math.MaxInt32
	var i int = 0
	var sum = 0

	for j := 0; j < len(nums); j++ {
		sum += nums[j]
		for sum >= target {
			res = min(res, j-i+1)
			sum -= nums[i]
			i++
		}
	}

	if res == math.MaxInt32 {
		return 0
	}

	return res
}
