package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindTargetSumWays(t *testing.T) {
	var nums []int = []int{1, 1, 1, 1, 1}
	var target int = 3
	var res int = findTargetSumWays(nums, target)
	assert.Equal(t, 5, res)

	nums = []int{1}
	target = 1
	res = findTargetSumWays(nums, target)
	assert.Equal(t, 1, res)

	nums = []int{0, 0, 0, 0, 0, 0, 0, 0, 1}
	target = 1
	res = findTargetSumWays(nums, target)
	assert.Equal(t, 256, res)
}
