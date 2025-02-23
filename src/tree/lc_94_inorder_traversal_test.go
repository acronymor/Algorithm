package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestInorderTraversal1(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = inorderTraversal1(root)
	assert.ElementsMatch(t, []int{1, 3, 2}, res)

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = inorderTraversal1(root)
	assert.ElementsMatch(t, []int{1}, res)
}

func TestInorderTraversal2(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res []int = inorderTraversal2(root)
	assert.ElementsMatch(t, []int{1, 3, 2}, res)

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = inorderTraversal2(root)
	assert.ElementsMatch(t, []int{1}, res)
}
