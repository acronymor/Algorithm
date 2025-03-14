package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxSubArray1(t *testing.T) {
	var nums []int = []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	var res = maxSubArray1(nums)
	assert.Equal(t, 6, res)

	nums = []int{5, 4, -1, 7, 8}
	res = maxSubArray1(nums)
	assert.Equal(t, 23, res)
}

func TestMaxSubArray2(t *testing.T) {
	var nums []int = []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	var res = maxSubArray2(nums)
	assert.Equal(t, 6, res)

	nums = []int{5, 4, -1, 7, 8}
	res = maxSubArray2(nums)
	assert.Equal(t, 23, res)
}
