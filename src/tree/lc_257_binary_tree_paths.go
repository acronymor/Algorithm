package tree

import "strconv"

/**
 * @brief 二叉树的所有路径
 *
 * @details
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 叶子节点 是指没有子节点的节点。
 *
 * @par 示例
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 * @see [leetcode-257](https://leetcode.cn/problems/binary-tree-paths/)
 */

func binaryTreePaths(root *TreeNode) []string {
	var preorder func(node *TreeNode, s string)

	var res []string
	preorder = func(node *TreeNode, s string) {
		if node == nil {
			return
		}

		s = s + strconv.Itoa(node.Val) + "->"
		if node.Left == nil && node.Right == nil {
			res = append(res, s[:len(s)-2])
		}

		preorder(node.Left, s)
		preorder(node.Right, s)
	}

	preorder(root, "")
	return res
}
