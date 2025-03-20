package tree

import "slices"

/**
 * @brief 打家劫舍 III
 *
 * @details
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。
 * 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树。
 * 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。 给定二叉树的 root 。
 * 返回 在不触动警报的情况下，小偷能够盗取的最高金额 。
 *
 * @par 示例
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 *      偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * @see [leetcode-337](https://leetcode.cn/problems/house-robber-iii/)
 */

func robiii(root *TreeNode) int {
	var order func(root *TreeNode) []int
	order = func(root *TreeNode) []int {
		if root == nil {
			return []int{0, 0}
		}

		left := order(root.Left)
		right := order(root.Right)

		robCur := root.Val + left[0] + right[0]
		notRobCur := slices.Max(left) + slices.Max(right)

		return []int{notRobCur, robCur}
	}

	var res = order(root)
	return slices.Max(res)
}
