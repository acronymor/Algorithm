package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRobiii(t *testing.T) {
	var nums []int = []int{3, 2, -1, 3, -1, -1, 3, -1, 1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res int = robiii(root)
	assert.Equal(t, 7, res)

	nums = []int{3, 4, 1, -1, -1, 3, -1, -1, 5, -1, 1, -1, -1}
	root = ToBinaryTree(nums)
	res = robiii(root)
	assert.Equal(t, 9, res)
}
