package array

/**
 * @brief 柱状图中最大的矩形
 *
 * @details
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 * @par 示例
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 * @see [leetcode-84](https://leetcode.cn/problems/largest-rectangle-in-histogram/)
 */

func largestRectangleArea(heights []int) int {
	var res int

	heights = append([]int{0}, heights...)
	heights = append(heights, 0)
	var stack []int = []int{0}

	for i := 0; i < len(heights); i++ {
		for len(stack) != 0 && heights[i] < heights[stack[len(stack)-1]] {
			top1 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			top2 := stack[len(stack)-1]

			var w int = i - top2 - 1
			var h int = heights[top1]

			res = max(res, w*h)
		}

		stack = append(stack, i)
	}

	return res
}
