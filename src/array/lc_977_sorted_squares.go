package array

/**
 * @brief 有序数组的平方
 *
 * @details
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 * @par 示例
 *
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 * @see [leetcode-977](https://leetcode.cn/problems/squares-of-a-sorted-array/)
 */

func sortedSquares(nums []int) []int {
	left, right := 0, len(nums)-1
	var res []int = make([]int, len(nums))
	for i := len(nums) - 1; i >= 0; i-- {
		if a, b := nums[left]*nums[left], nums[right]*nums[right]; a > b {
			res[i] = a
			left++
		} else {
			res[i] = b
			right--
		}
	}
	return res
}
