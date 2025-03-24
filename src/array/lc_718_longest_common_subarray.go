package array

/**
 * @brief 最长重复子数组
 *
 * @details
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 *
 * @par 示例
 *
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 *
 * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * 输出：5
 *
 * @see [leetcode-718](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/)
 */

func findLength(nums1 []int, nums2 []int) int {
	var dp [][]int = make([][]int, len(nums1)+1)
	for i := 0; i <= len(nums1); i++ {
		dp[i] = make([]int, len(nums2)+1)
	}

	var maxResult int = dp[0][0]
	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			}
			if maxResult < dp[i][j] {
				maxResult = dp[i][j]
			}
		}
	}

	return maxResult
}
