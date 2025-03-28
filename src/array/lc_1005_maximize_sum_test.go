package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLargestSumAfterKNegations(t *testing.T) {
	var nums []int = []int{4, 2, 3}
	var k int = 1
	var res int = largestSumAfterKNegations(nums, k)
	assert.Equal(t, 5, res)

	nums = []int{3, -1, 0, 2}
	k = 6
	res = largestSumAfterKNegations(nums, k)
	assert.Equal(t, 6, res)

	nums = []int{2, -3, -1, 5, -4}
	k = 2
	res = largestSumAfterKNegations(nums, k)
	assert.Equal(t, 13, res)
}
