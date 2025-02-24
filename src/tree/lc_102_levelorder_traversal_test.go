package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLevelOrder(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1, -1, -1}
	var root *TreeNode = ToBinaryTree(nums)
	var res [][]int = levelOrder(root)
	assert.ElementsMatch(t, []int{1}, res[0])
	assert.ElementsMatch(t, []int{2}, res[1])
	assert.ElementsMatch(t, []int{3}, res[2])

	nums = []int{1, -1, -1}
	root = ToBinaryTree(nums)
	res = levelOrder(root)
	assert.ElementsMatch(t, []int{1}, res[0])

	nums = []int{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1}
	root = ToBinaryTree(nums)
	res = levelOrder(root)
	assert.ElementsMatch(t, []int{3}, res[0])
	assert.ElementsMatch(t, []int{9, 20}, res[1])
	assert.ElementsMatch(t, []int{15, 7}, res[2])
}
