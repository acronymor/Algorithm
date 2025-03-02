package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLowestCommonAncestorBst1(t *testing.T) {
	var nums []int = []int{6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = lowestCommonAncestorBst1(root, root.Left, root.Right)
	assert.Equal(t, 6, res.Val)

	nums = []int{6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestorBst1(root, root.Left, root.Left.Right)
	assert.Equal(t, 2, res.Val)

	nums = []int{3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestorBst1(root, root.Left, root.Right)
	assert.Equal(t, 3, res.Val)

	nums = []int{1, 2, -1, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestorBst1(root, root, root.Left)
	assert.Equal(t, 1, res.Val)
}

func TestLowestCommonAncestorBst2(t *testing.T) {
	var nums []int = []int{6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = lowestCommonAncestorBst2(root, root.Left, root.Right)
	assert.Equal(t, 6, res.Val)

	nums = []int{6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestorBst2(root, root.Left, root.Left.Right)
	assert.Equal(t, 2, res.Val)

	nums = []int{3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestorBst2(root, root.Left, root.Right)
	assert.Equal(t, 3, res.Val)

	nums = []int{1, 2, -1, -1, -1}
	root = ToBinaryTree(nums)
	res = lowestCommonAncestorBst2(root, root, root.Left)
	assert.Equal(t, 1, res.Val)
}
