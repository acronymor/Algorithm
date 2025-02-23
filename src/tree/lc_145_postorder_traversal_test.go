package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPostorderTraversal1(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = postorderTraversal1(root)
	assert.ElementsMatch(t, []int{3, 2, 1}, res)

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = postorderTraversal1(root)
	assert.ElementsMatch(t, []int{1}, res)
}

func TestPostorderTraversal2(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = postorderTraversal2(root)
	assert.ElementsMatch(t, []int{3, 2, 1}, res)

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = postorderTraversal2(root)
	assert.ElementsMatch(t, []int{1}, res)
}
