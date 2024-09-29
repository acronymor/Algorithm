package array

/**
 * @brief 删除有序数组中的重复项
 *
 * @details
 * 给你一个升序排列的数组 nums ，请你原地删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的
 * 相对顺序 应该保持 一致 。
 *
 * @par 示例
 *
 * 输入：nums = [1,1,2]
 * 输出：2, nums = [1,2,_]
 * 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
 *
 * 输入：nums = [0,0,1,1,1,2,2,3,3,4]
 * 输出：5, nums = [0,1,2,3,4]
 * 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。
 * 不需要考虑数组中超出新长度后面的元素。
 *
 * @see [leetcode-26](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)
 */

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	var i int = 1
	for j := 1; j < len(nums); j++ {
		if nums[j-1] != nums[j] {
			nums[i] = nums[j]
			i++
		}
	}
	return i
}
