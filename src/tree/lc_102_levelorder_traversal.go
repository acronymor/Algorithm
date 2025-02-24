package tree

/**
 * @brief 二叉树的层序遍历
 *
 * @details
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 *
 * @par 示例
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 * 输入：root = []
 * 输出：[]
 *
 * @see [leetcode-102](https://leetcode.cn/problems/binary-tree-level-order-traversal/)
 */

func levelOrder(root *TreeNode) [][]int {
	var res [][]int

	if root == nil {
		return res
	}

	var queue []*TreeNode
	queue = append(queue, root)

	for len(queue) != 0 {
		var v []int
		var size = len(queue)

		for i := 0; i < size; i++ {
			var node *TreeNode = queue[0]
			queue = queue[1:]
			v = append(v, node.Val)

			if node.Left != nil {
				queue = append(queue, node.Left)
			}

			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		res = append(res, v)
	}

	return res
}
