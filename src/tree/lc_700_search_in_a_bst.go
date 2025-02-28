package tree

/**
 * @brief 二叉搜索树中的搜索
 *
 * @details
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
 *
 * @par 示例
 *
 * 输入：root = [4,2,7,1,3], val = 2
 * 输出：[2,1,3]
 *
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[]
 *
 * @see [leetcode-700](https://leetcode.cn/problems/search-in-a-binary-search-tree/)
 */

func searchBST1(root *TreeNode, val int) *TreeNode {
	var order func(node *TreeNode, val int)

	var head *TreeNode = nil

	order = func(node *TreeNode, val int) {
		if node == nil {
			return
		}

		if node.Val == val {
			head = node
			return
		}

		order(node.Left, val)
		order(node.Right, val)
		return
	}

	order(root, val)

	return head
}

func searchBST2(root *TreeNode, val int) *TreeNode {
	if root == nil || root.Val == val {
		return root
	}

	if root.Val > val {
		return searchBST2(root.Left, val)
	}

	return searchBST2(root.Right, val)
}
