package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMinSubArrayLen(t *testing.T) {
	var nums []int = []int{2, 3, 1, 2, 4, 3}
	var target = 7
	var res int = minSubArrayLen(target, nums)
	assert.Equal(t, 2, res)

	nums = []int{1, 4, 4}
	target = 4
	res = minSubArrayLen(target, nums)
	assert.Equal(t, 1, res)

	nums = []int{1, 1, 1, 1, 1, 1, 1, 1}
	target = 11
	res = minSubArrayLen(target, nums)
	assert.Equal(t, 0, res)

	nums = []int{1, 2, 3, 4, 5}
	target = 11
	res = minSubArrayLen(target, nums)
	assert.Equal(t, 3, res)
}
