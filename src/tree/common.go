package tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var i int = 0

func toBinaryTree(root *TreeNode, nums []int) *TreeNode {
	if nums[i] == -1 || i > len(nums) {
		return root
	}

	root = &TreeNode{nums[i], nil, nil}
	i++
	root.Left = toBinaryTree(root.Left, nums)
	i++
	root.Right = toBinaryTree(root.Right, nums)

	return root
}

func ToBinaryTree(nums []int) *TreeNode {
	i = 0

	var root *TreeNode = nil
	if len(nums) < 1 {
		return root
	}

	root = toBinaryTree(root, nums)
	return root
}
