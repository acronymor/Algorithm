package array

import "sort"

/**
 * @brief 合并两个有序数组
 *
 * @details
 *
 * 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 * 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 * 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
 * 为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
 * @par 示例
 *
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：[1,2,2,3,5,6]
 *
 * 输入：nums1 = [1], m = 1, nums2 = [], n = 0
 * 输出：[1]
 *
 * 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
 * 输出：[1]
 *
 * @see [leetcode-84](https://leetcode.cn/problems/merge-sorted-array/)
 */

func mergeSortedArray1(nums1 []int, m int, nums2 []int, _ int) {
	copy(nums1[m:], nums2)
	sort.Ints(nums1)
}

func mergeSortedArray2(nums1 []int, m int, nums2 []int, n int) {
	for i := len(nums1) - 1; n > 0; i-- {
		if m == 0 {
			copy(nums1, nums2[0:n])
			return
		}

		if nums2[n-1] > nums1[m-1] {
			nums1[i] = nums2[n-1]
			n--
		} else {
			nums1[i] = nums1[m-1]
			m--
		}
	}
}
