package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestBinarySearch1(t *testing.T) {
	var nums []int = []int{-1, 0, 3, 5, 9, 12}
	var target = 9
	var res int = binarySearch1(nums, target)
	assert.Equal(t, 4, res)

	nums = []int{-1, 0, 3, 5, 9, 12}
	target = 2
	res = binarySearch1(nums, target)
	assert.Equal(t, -1, res)

	nums = []int{5}
	target = 5
	res = binarySearch1(nums, target)
	assert.Equal(t, 0, res)
}

func TestBinarySearch2(t *testing.T) {
	var nums []int = []int{-1, 0, 3, 5, 9, 12}
	var target = 9
	var res int = binarySearch2(nums, target)
	assert.Equal(t, 4, res)

	nums = []int{-1, 0, 3, 5, 9, 12}
	target = 2
	res = binarySearch2(nums, target)
	assert.Equal(t, -1, res)

	nums = []int{5}
	target = 5
	res = binarySearch2(nums, target)
	assert.Equal(t, 0, res)
}
