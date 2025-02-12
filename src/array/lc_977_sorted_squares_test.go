package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSortedSquares(t *testing.T) {
	var nums []int = []int{-4, -1, 0, 3, 10}
	var res []int = sortedSquares(nums)
	assert.ObjectsAreEqual([]int{0, 1, 9, 16, 100}, res)

	nums = []int{-7, -3, 2, 3, 11}
	res = sortedSquares(nums)
	assert.ObjectsAreEqual([]int{4, 9, 9, 49, 121}, res)
}
