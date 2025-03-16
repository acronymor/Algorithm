package array

/**
 * @brief 目标和
 *
 * @details
 * 给你一个整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 * @par 示例
 *
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 * @see [leetcode-494](https://leetcode.cn/problems/target-sum/)
 */

func findTargetSumWays(nums []int, target int) int {
	var sumVal = 0
	for _, num := range nums {
		sumVal += num
	}

	var bagSize int = (sumVal + target) / 2
	if bagSize < 0 || (sumVal+target)%2 != 0 {
		return 0
	}

	var dp [][]int = make([][]int, len(nums))
	for i := 0; i < len(nums); i++ {
		dp[i] = make([]int, bagSize+1)
	}

	dp[0][0] = 1
	if nums[0] == 0 {
		dp[0][nums[0]] = dp[0][0] + 1
	} else {
		dp[0][nums[0]] = 1
	}

	for i := 1; i < len(nums); i++ {
		for j := 0; j <= bagSize; j++ {
			if nums[i] > j {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
			}
		}
	}

	return dp[len(nums)-1][bagSize]
}
