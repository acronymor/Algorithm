package array

import "math"

/**
 * @brief 完全平方数
 *
 * @details
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16
 * 都是完全平方数，而 3 和 11 不是。
 *
 * @par 示例
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 * @see [leetcode-279](https://leetcode.cn/problems/perfect-squares/)
 */

func numSquares(n int) int {
	var dp []int = make([]int, n+1)
	dp[0] = 0
	for j := 1; j <= n; j++ {
		dp[j] = math.MaxInt32
	}

	for i := 0; i <= n; i++ {
		for j := i * i; j <= n; j++ {
			dp[j] = min(dp[j], dp[j-i*i]+1)
		}
	}

	return dp[n]
}
