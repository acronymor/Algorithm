package array

/**
 * @brief 最长连续序列
 *
 * @details
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 * @par 示例
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 * @see [leetcode-128](https://leetcode.cn/problems/longest-consecutive-sequence/)
 */

func longestConsecutive(nums []int) int {
	var table map[int]bool = make(map[int]bool, len(nums))

	for _, num := range nums {
		table[num] = true
	}

	var res int = 0
	var ans int = 0
	for _, num := range nums {
		if _, ok := table[num-1]; ok {
			continue
		}

		ans = 0
		cur := num
		for table[cur] {
			cur++
			ans++
		}

		res = max(res, ans)
	}

	return res
}
