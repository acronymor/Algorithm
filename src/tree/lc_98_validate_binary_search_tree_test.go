package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIsValidBST(t *testing.T) {
	var nums []int = []int{2, 1, -1, -1, 3, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res bool = isValidBST(root)
	assert.True(t, res)

	nums = []int{5, 1, -1, -1, 4, 3, -1, -1, 6, -1, -1}
	root = ToBinaryTree(nums)
	res = isValidBST(root)
	assert.False(t, res)
}
