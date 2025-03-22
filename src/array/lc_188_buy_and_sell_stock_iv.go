package array

/**
 * @brief 买卖股票的最佳时机 IV
 *
 * @details
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * @par 示例
 *
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2
 *
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 *    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 *
 * @see [leetcode-188](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)
 */

func maxProfitIV(prices []int, k int) int {
	var length = len(prices)
	var dp [][]int = make([][]int, length)
	for i := 0; i < length; i++ {
		dp[i] = make([]int, 2*k)
	}

	for i := 0; i < 2*k; i += 2 {
		dp[0][i] = 0 - prices[0]
	}

	for i := 1; i < length; i++ {
		for j := 0; j < 2*k; j++ {
			if j == 0 {
				dp[i][j] = max(dp[i-1][j], 0-prices[i])
			} else {
				var price int
				if j%2 != 0 {
					price = prices[i]
				} else {
					price = -prices[i]
				}
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+price)
			}
		}
	}

	return dp[length-1][2*k-1]
}
