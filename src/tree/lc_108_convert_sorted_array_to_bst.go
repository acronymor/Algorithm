package tree

/**
 * @brief 将有序数组转换为二叉搜索树
 *
 * @details
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
 *
 * @par 示例
 *
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 *
 * 输入：nums = [1,3]
 * 输出：[3,1]
 *
 * @see [leetcode-108](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)
 */

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}

	idx := len(nums) / 2

	root := &TreeNode{nums[idx], nil, nil}
	root.Left = sortedArrayToBST(nums[:idx])
	root.Right = sortedArrayToBST(nums[idx+1:])

	return root
}
