package tree

/**
 * @brief 二叉搜索树中的众数
 *
 * @details
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
 *
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 *
 * 假定 BST 满足如下定义：
 *
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 *
 * @par 示例
 *
 * 输入：root = [1,null,2,2]
 * 输出：[2]
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 * @see [leetcode-501](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)
 */

func findMode(root *TreeNode) []int {
	var res []int

	if root == nil {
		return res
	}

	var stack []*TreeNode
	var pre *TreeNode = nil
	var cur *TreeNode = root

	var count int = 0
	var maxCount int = 0

	for cur != nil || len(stack) != 0 {
		if cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		} else {
			cur = stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			if pre == nil {
				count = 1
			} else if pre.Val == cur.Val {
				count++
			} else {
				count = 1
			}

			if count == maxCount {
				res = append(res, cur.Val)
			}

			if count > maxCount {
				maxCount = count
				res = make([]int, 0)
				res = append(res, cur.Val)
			}

			pre = cur
			cur = cur.Right
		}
	}

	return res
}
