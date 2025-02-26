package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestBinaryTreePaths(t *testing.T) {
	var nums []int = []int{1, 2, -1, 5, -1, -1, 3, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []string = binaryTreePaths(root)
	assert.Equal(t, "1->2->5", res[0])
	assert.Equal(t, "1->3", res[1])

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = binaryTreePaths(root)
	assert.Equal(t, "1", res[0])
}
