package tree

import "math"

/**
 * @brief 验证二叉搜索树
 *
 * @details
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 * @par 示例
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：[0]
 *
 * @see [leetcode-98](https://leetcode.cn/problems/validate-binary-search-tree/)
 */

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}

	var stack []*TreeNode

	var cur *TreeNode = root
	var tmp int = math.MinInt64

	for cur != nil || len(stack) != 0 {
		if cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		} else {
			cur = stack[len(stack)-1]
			if cur.Val <= tmp {
				return false
			}

			stack = stack[:len(stack)-1]
			tmp = cur.Val
			cur = cur.Right
		}
	}

	return true
}
