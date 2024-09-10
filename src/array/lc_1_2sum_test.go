package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestTwoSum(t *testing.T) {
	var nums []int
	var target int
	var res []int

	nums = []int{2, 7, 11, 15}
	target = 9
	res = twoSum(nums, target)
	assert.Equal(t, res, []int{0, 1})

	nums = []int{3, 2, 4}
	target = 6
	res = twoSum(nums, target)
	assert.Equal(t, res, []int{1, 2})

	nums = []int{3, 3}
	target = 6
	res = twoSum(nums, target)
	assert.Equal(t, res, []int{0, 1})
}
