package array

/**
 * @brief 爬楼梯
 *
 * @details
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * @par 示例
 *
 * 输入：n = 2
 * 输出：2
 *
 * 输入：n = 3
 * 输出：3
 *
 * @see [leetcode-70](https://leetcode.cn/problems/climbing-stairs/)
 */

func climbStairs(n int) int {
	var dp []int = make([]int, n+1)

	dp[0] = 0
	dp[1] = 1
	dp[2] = 2

	for i := 3; i <= n; i++ {
		dp[i] = dp[i-2] + dp[i-1]
	}

	return dp[n]
}
