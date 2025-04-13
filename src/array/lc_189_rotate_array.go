package array

/**
 * @brief 轮转数组
 *
 * @details
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 *
 * @par 示例
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 *
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 *
 * @see [leetcode-189](https://leetcode.cn/problems/rotate-array/)
 */

func rotate1(nums []int, k int) {
	newNums := make([]int, len(nums))

	for i, num := range nums {
		newNums[(i+k)%len(nums)] = num
	}

	copy(nums, newNums)
}

func rotate2(nums []int, k int) {
	var reverse func(newNums []int)

	reverse = func(newNums []int) {
		for i, n := 0, len(newNums)-1; i < len(newNums)/2; i++ {
			newNums[i], newNums[n-i] = newNums[n-i], newNums[i]
		}
	}

	k = k % len(nums)
	reverse(nums)
	reverse(nums[:k])
	reverse(nums[k:])
}
