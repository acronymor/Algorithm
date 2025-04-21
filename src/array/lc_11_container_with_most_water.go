package array

/**
 * @brief 盛最多水的容器
 *
 * @details
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 *
 * @par 示例
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 *
 * 输入：height = [1,1]
 * 输出：1
 *
 * @see [leetcode-11](https://leetcode.cn/problems/container-with-most-water/)
 */

func maxArea(height []int) int {
	left, right := 0, len(height)-1
	var res = 0
	for left < right {
		l := height[left]
		r := height[right]
		res = max(res, (right-left)*min(l, r))
		if l < r {
			left++
		} else {
			right--
		}
	}

	return res
}
