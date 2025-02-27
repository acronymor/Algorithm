package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMergeTrees(t *testing.T) {
	var nums1 []int = []int{1, 3, 5, -1, -1, -1, 2, -1, -1}
	var root1 *TreeNode = ToBinaryTree(nums1)

	var nums2 []int = []int{2, 1, -1, 4, -1, -1, 3, -1, 7, -1, -1}
	var root2 *TreeNode = ToBinaryTree(nums2)

	var root *TreeNode = mergeTrees(root1, root2)
	assert.Equal(t, 3, root.Val)
	assert.Equal(t, 4, root.Left.Val)
	assert.Equal(t, 5, root.Right.Val)
}
