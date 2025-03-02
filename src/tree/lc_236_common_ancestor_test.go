package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLowestCommonAncestor(t *testing.T) {
	var nums []int = []int{3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = lowestCommonAncestor(root, root.Left, root.Right)
	assert.Equal(t, 3, res.Val)

	nums = []int{3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestor(root, root.Left, root.Left.Right.Left)
	assert.Equal(t, 5, res.Val)

	nums = []int{1, 2, -1, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestor(root, root, root.Left)
	assert.Equal(t, 1, res.Val)

	nums = []int{37, -34, -1, -100, -1, -1, -48, -101, -1, -1, 48, -54, -71, -1, -1, -22, -1, 8, -1, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestor(root, root.Right.Right, root.Right.Right.Left.Left)
	assert.Equal(t, 48, res.Val)
}
