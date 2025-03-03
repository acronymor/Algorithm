package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestInsertIntoBST(t *testing.T) {
	var nums []int = []int{4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = insertIntoBST(root, 5)
	assert.Equal(t, 5, res.Right.Left.Val)
}
