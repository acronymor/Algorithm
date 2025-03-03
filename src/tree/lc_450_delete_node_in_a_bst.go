package tree

/**
 * @brief 二叉搜索树中的插入操作
 *
 * @details
 * 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
 *
 * 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
 *
 * @par 示例
 *
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[4,2,7,1,3,5]
 *
 * 输入：root = [40,20,60,10,30,50,70], val = 25
 * 输出：[40,20,60,10,30,50,70,null,null,25]
 *
 * @see [leetcode-701](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)
 */

func deleteNode(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return nil
	}

	if val < root.Val {
		root.Left = deleteNode(root.Left, val)
	}

	if val > root.Val {
		root.Right = deleteNode(root.Right, val)
	}

	// BST 不包含值为  val 的节点
	if val != root.Val {
		return root
	}

	// 左子树为空，所以返回右子树
	if root.Left == nil {
		return root.Right
	}

	// 右子树为空，所以返回左子树
	if root.Right == nil {
		return root.Left
	}

	// 两个子树都不为空
	node := root.Right
	for node.Left != nil {
		node = node.Left
	}
	node.Left = root.Left
	root = root.Right

	return root
}
