package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSearchBST1(t *testing.T) {
	var nums []int = []int{4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = searchBST1(root, 2)
	assert.Equal(t, 2, res.Val)
	assert.Equal(t, 1, res.Left.Val)
	assert.Equal(t, 3, res.Right.Val)

	res = searchBST1(root, 5)
	assert.Nil(t, res)
}

func TestSearchBST2(t *testing.T) {
	var nums []int = []int{4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res *TreeNode = searchBST2(root, 2)
	assert.Equal(t, 2, res.Val)
	assert.Equal(t, 1, res.Left.Val)
	assert.Equal(t, 3, res.Right.Val)

	res = searchBST2(root, 5)
	assert.Nil(t, res)
}
