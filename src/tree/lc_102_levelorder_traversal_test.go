package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func BuildBinaryTree(nums []int) *TreeNode {
	var idx int = 0
	var root = &TreeNode{Val: nums[idx], Left: nil, Right: nil}
	var queue = []*TreeNode{root}

	for len(queue) != 0 {
		var size = len(queue)

		for i := 0; i < size; i++ {
			node := queue[0]
			queue = queue[1:]

			idx++
			if idx < len(nums) && nums[idx] != -1 {
				node.Left = &TreeNode{Val: nums[idx], Left: nil, Right: nil}
				queue = append(queue, node.Left)
			}

			idx++
			if idx < len(nums) && nums[idx] != -1 {
				node.Right = &TreeNode{Val: nums[idx], Left: nil, Right: nil}
				queue = append(queue, node.Right)
			}
		}
	}

	return root
}

func TestLevelOrder1(t *testing.T) {
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

func TestLevelOrder2(t *testing.T) {
	var nums []int = []int{1, -1, 2, 3, -1}
	var root *TreeNode = BuildBinaryTree(nums)
	var res [][]int = levelOrder(root)
	assert.ElementsMatch(t, []int{1}, res[0])
	assert.ElementsMatch(t, []int{2}, res[1])
	assert.ElementsMatch(t, []int{3}, res[2])

	nums = []int{1}
	root = BuildBinaryTree(nums)
	res = levelOrder(root)
	assert.ElementsMatch(t, []int{1}, res[0])

	nums = []int{3, 9, 20, -1, -1, 15, 7}
	root = BuildBinaryTree(nums)
	res = levelOrder(root)
	assert.ElementsMatch(t, []int{3}, res[0])
	assert.ElementsMatch(t, []int{9, 20}, res[1])
	assert.ElementsMatch(t, []int{15, 7}, res[2])
}
