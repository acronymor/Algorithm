package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindMode(t *testing.T) {
	var nums []int = []int{1, -1, 2, 2, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = findMode(root)
	assert.Equal(t, 2, res[0])

	nums = []int{0, -1, -1}
	root = ToBinaryTree(nums)
	res = findMode(root)
	assert.Equal(t, 0, res[0])
}
