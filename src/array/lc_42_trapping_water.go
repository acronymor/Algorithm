package array

/**
 * @brief 接雨水
 *
 * @details
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * @par 示例
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 * @see [leetcode-42](https://leetcode.cn/problems/trapping-rain-water/)
 * @see
 * [详细通俗的思路分析，多解法](https://leetcode.cn/problems/trapping-rain-water/solutions/9112/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)
 */

func trap(height []int) int {
	var res int = 0
	var stack []int

	for i := 0; i < len(height); i++ {
		for len(stack) != 0 && height[i] > height[stack[len(stack)-1]] {
			top1 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			if len(stack) == 0 {
				break
			}

			top2 := stack[len(stack)-1]

			var h = min(height[top2], height[i])
			res += (i - top2 - 1) * (h - height[top1])
		}
		stack = append(stack, i)
	}

	return res
}
