package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSortedArrayToBST(t *testing.T) {
	var nums []int = []int{-10, -3, 0, 5, 9}
	var res *TreeNode = sortedArrayToBST(nums)
	assert.Equal(t, 0, res.Val)
	assert.Equal(t, -3, res.Left.Val)
	assert.Equal(t, -10, res.Left.Left.Val)
	assert.Equal(t, 9, res.Right.Val)
	assert.Equal(t, 5, res.Right.Left.Val)
}
