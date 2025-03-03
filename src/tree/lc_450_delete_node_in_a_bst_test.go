package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestDeleteNode(t *testing.T) {
	var nums []int = []int{5, 3, 2, -1, -1, 4, -1, -1, 6, -1, 7, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = deleteNode(root, 3)
	assert.Equal(t, 4, res.Left.Val)

	nums = []int{0, -1, -1}
	root = ToBinaryTree(nums)
	res = deleteNode(root, 0)
	assert.Nil(t, res)
}
