package tree

/**
 * @brief 二叉树的后序遍历
 *
 * @details
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *
 * @par 示例
 *
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
 *
 * 输入：root = []
 * 输出：[]
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 * @see [leetcode-145](https://leetcode.cn/problems/binary-tree-postorder-traversal/)
 */

func postorderTraversal1(root *TreeNode) (vals []int) {
	var postorder func(node *TreeNode)
	postorder = func(node *TreeNode) {
		if node == nil {
			return
		}

		postorder(node.Left)
		postorder(node.Right)
		vals = append(vals, node.Val)
	}

	postorder(root)

	return
}

func postorderTraversal2(root *TreeNode) (vals []int) {
	if root == nil {
		return
	}

	var stack []*TreeNode
	stack = append(stack, root)

	for len(stack) != 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		vals = append(vals, node.Val)

		if node.Left != nil {
			stack = append(stack, node.Left)
		}

		if node.Right != nil {
			stack = append(stack, node.Right)
		}
	}

	for i, j := 0, len(vals)-1; i < j; i, j = i+1, j-1 {
		vals[i], vals[j] = vals[j], vals[i]
	}

	return
}
