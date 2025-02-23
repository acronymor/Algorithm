package tree

/**
 * @brief 二叉树的中序遍历
 *
 * @details
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 *
 * @par 示例
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 *
 * 输入：root = []
 * 输出：[]
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 * @see [leetcode-94](https://leetcode.cn/problems/binary-tree-inorder-traversal/)
 */

func inorderTraversal1(root *TreeNode) (vals []int) {
	var inorder func(node *TreeNode)
	inorder = func(node *TreeNode) {
		if node == nil {
			return
		}

		inorder(node.Left)
		vals = append(vals, node.Val)
		inorder(node.Right)
	}

	inorder(root)

	return
}

func inorderTraversal2(root *TreeNode) (vals []int) {
	if root == nil {
		return
	}

	var stack []*TreeNode
	var cur *TreeNode = root
	for cur != nil || len(stack) != 0 {
		if cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		} else {
			cur = stack[len(stack)-1]
			vals = append(vals, cur.Val)
			stack = stack[:len(stack)-1]
			cur = cur.Right
		}
	}
	return
}
