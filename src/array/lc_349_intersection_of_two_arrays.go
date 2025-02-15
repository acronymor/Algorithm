package array

/**
 * @brief 两个数组的交集
 *
 * @details
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 * @par 示例
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 * @see [leetcode-349](https://leetcode.cn/problems/intersection-of-two-arrays)
 */

func intersection(nums1 []int, nums2 []int) []int {
	var table map[int]bool = make(map[int]bool, len(nums1))
	for _, num := range nums1 {
		table[num] = true
	}

	var res []int
	for _, num := range nums2 {
		if _, ok := table[num]; ok {
			res = append(res, num)
			delete(table, num)
		}
	}

	return res
}
