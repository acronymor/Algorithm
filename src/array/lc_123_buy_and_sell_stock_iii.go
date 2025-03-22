package array

/**
 * @brief 买卖股票的最佳时机 III
 *
 * @details
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * @par 示例
 *
 * 输入：prices = [3,3,5,0,0,3,1,4]
 * 输出：6
 * 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3。
 *
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 *
 * @see [leetcode-123](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)
 */

func maxProfitIII(prices []int) int {
	var length = len(prices)
	var dp [][]int = make([][]int, length)
	for i := 0; i < length; i++ {
		dp[i] = make([]int, 5)
	}

	dp[0][1] = -prices[0]
	dp[0][3] = -prices[0]

	for i := 1; i < length; i++ {
		dp[i][1] = max(dp[i-1][1], 0-prices[i])
		dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i])
		dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i])
		dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i])
	}

	return dp[length-1][4]
}
