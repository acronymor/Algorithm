package tree

func preorderTraversal1(root *TreeNode) (vals []int) {
	var preorder func(node *TreeNode)
	preorder = func(node *TreeNode) {
		if node == nil {
			return
		}

		vals = append(vals, node.Val)
		preorder(node.Left)
		preorder(node.Right)
	}

	preorder(root)
	return
}

func preorderTraversal2(root *TreeNode) (vals []int) {
	if root == nil {
		return vals
	}

	var stack []*TreeNode

	stack = append(stack, root)

	for len(stack) != 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		vals = append(vals, node.Val)

		if node.Right != nil {
			stack = append(stack, node.Right)
		}

		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}

	return
}
