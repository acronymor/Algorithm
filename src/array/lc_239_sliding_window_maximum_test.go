package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxSlidingWindow1(t *testing.T) {
	var nums []int = []int{1, 3, -1, -3, 5, 3, 6, 7}
	var k int = 3
	assert.ElementsMatch(t, []int{3, 3, 5, 5, 6, 7}, maxSlidingWindow1(nums, k))

	nums = []int{1}
	k = 1
	assert.ElementsMatch(t, []int{1}, maxSlidingWindow1(nums, k))

	nums = []int{1, -1}
	k = 1
	assert.ElementsMatch(t, []int{1, -1}, maxSlidingWindow1(nums, k))
}

func TestMaxSlidingWindow2(t *testing.T) {
	var nums []int = []int{1, 3, -1, -3, 5, 3, 6, 7}
	var k int = 3
	assert.ElementsMatch(t, []int{3, 3, 5, 5, 6, 7}, maxSlidingWindow2(nums, k))

	nums = []int{1}
	k = 1
	assert.ElementsMatch(t, []int{1}, maxSlidingWindow2(nums, k))

	nums = []int{1, -1}
	k = 1
	assert.ElementsMatch(t, []int{1, -1}, maxSlidingWindow2(nums, k))
}
