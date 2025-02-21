package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPreorderTraversal1(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = preorderTraversal1(root)
	assert.ElementsMatch(t, []int{1, 2, 3}, res)

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = preorderTraversal1(root)
	assert.ElementsMatch(t, []int{1}, res)
}

func TestPreorderTraversal2(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = preorderTraversal2(root)
	assert.ElementsMatch(t, []int{1, 2, 3}, res)

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = preorderTraversal2(root)
	assert.ElementsMatch(t, []int{1}, res)
}
