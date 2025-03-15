package array

/**
 * @brief 分割等和子集
 *
 * @details
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * @par 示例
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 *
 * @see [leetcode-416](https://leetcode.cn/problems/partition-equal-subset-sum/)
 */

func canPartition(nums []int) bool {
	var dp [][]int = make([][]int, len(nums))

	var sumValue int = 0
	for _, num := range nums {
		sumValue += num
	}

	if sumValue%2 == 1 {
		return false
	}

	var avgValue = sumValue / 2

	for i := 0; i < len(nums); i++ {
		dp[i] = make([]int, avgValue+1)
	}

	for j := 0; j < avgValue; j++ {
		if nums[0] <= j {
			dp[0][j] = nums[0]
		}
	}

	for i := 1; i < len(nums); i++ {
		for j := 0; j <= avgValue; j++ {
			if nums[i] > j {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]]+nums[i])
			}
		}
	}

	return dp[len(nums)-1][avgValue] == avgValue
}
