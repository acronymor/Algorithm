package math

/**
 * @brief 整数拆分
 *
 * @details
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 返回 你可以获得的最大乘积 。
 *
 * @par 示例
 *
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * @see [leetcode-343](https://leetcode.cn/problems/integer-break/)
 */

func integerBreak(n int) int {
	var dp []int = make([]int, n+1)

	dp[0] = 0
	dp[1] = 1
	dp[2] = 1

	for i := 3; i <= n; i++ {
		for j := 2; j < i; j++ {
			dp[i] = max(max(j*(i-j), j*dp[i-j]), dp[i])
		}
	}

	return dp[n]
}
