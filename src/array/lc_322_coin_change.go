package array

import (
	"math"
)

/**
 * @brief 零钱兑换
 *
 * @details
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 *
 * @par 示例
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * @see [leetcode-322](https://leetcode.cn/problems/coin-change/)
 */

func coinChange1(coins []int, amount int) int {
	var dp []int = make([]int, amount+1)
	dp[0] = 0

	for j := 1; j <= amount; j++ {
		dp[j] = math.MaxInt32
	}

	for i := 0; i < len(coins); i++ {
		for j := coins[i]; j <= amount; j++ {
			dp[j] = min(dp[j], dp[j-coins[i]]+1)
		}
	}

	if dp[amount] == math.MaxInt32 {
		return -1
	}
	return dp[amount]
}

func coinChange2(coins []int, amount int) int {
	if amount == 0 {
		return 0
	}

	var res [][]int = make([][]int, 0)
	var ans []int = make([]int, 0)

	var backtrace func(idx int, target int)
	backtrace = func(idx int, target int) {
		if target < 0 {
			return
		}

		if target == 0 {
			tmp := make([]int, len(ans))
			copy(tmp, ans)
			res = append(res, tmp)
			return
		}

		for i := idx; i < len(coins); i++ {
			ans = append(ans, coins[i])
			backtrace(i, target-coins[i])
			ans = ans[:len(ans)-1]
		}
	}

	backtrace(0, amount)

	var minVal = math.MaxInt32
	if len(res) == 0 {
		minVal = -1
	}
	for _, item := range res {
		if len(item) < minVal {
			minVal = len(item)
		}
	}
	return minVal
}
