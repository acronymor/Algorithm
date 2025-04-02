package array

/**
 * @brief 下一个更大元素 I
 *
 * @details
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
 * 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
 * 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的
 * 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。 返回一个长度为 nums1.length 的数组 ans
 * 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 *
 * @par 示例
 *
 * 输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出：[-1,3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * <4>，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * <1>，nums2 = [1,3,4,2]。下一个更大元素是 3 。
 * <2>，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 *
 * 输入：nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出：[3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * <2> ，nums2 = [1,2,3,4]。下一个更大元素是 3 。
 * <4> ，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
 *
 * @see [leetcode-496](https://leetcode.cn/problems/next-greater-element-i/)
 */

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	var table map[int]int = make(map[int]int, len(nums2))
	var stack []int

	for i := 0; i < len(nums2); i++ {
		for len(stack) != 0 && nums2[i] > nums2[stack[len(stack)-1]] {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			table[nums2[top]] = nums2[i]
		}
		stack = append(stack, i)
	}

	var res []int = make([]int, len(nums1))
	for i, num := range nums1 {
		if val, ok := table[num]; ok {
			res[i] = val
		} else {
			res[i] = -1
		}
	}

	return res
}
