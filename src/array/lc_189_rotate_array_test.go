package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRotate1(t *testing.T) {
	var nums []int = []int{1, 2, 3, 4, 5, 6, 7}
	var k int = 3
	rotate1(nums, k)
	assert.ElementsMatch(t, []int{5, 6, 7, 1, 2, 3, 4}, nums)

	nums = []int{-1, -100, 3, 99}
	k = 2
	rotate1(nums, k)
	assert.ElementsMatch(t, []int{3, 99, -1, -100}, nums)
}

func TestRotate2(t *testing.T) {
	var nums []int = []int{1, 2, 3, 4, 5, 6, 7}
	var k int = 3
	rotate2(nums, k)
	assert.ElementsMatch(t, []int{5, 6, 7, 1, 2, 3, 4}, nums)

	nums = []int{-1, -100, 3, 99}
	k = 2
	rotate2(nums, k)
	assert.ElementsMatch(t, []int{3, 99, -1, -100}, nums)
}
