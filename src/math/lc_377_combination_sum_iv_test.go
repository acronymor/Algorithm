package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCombinationSum4(t *testing.T) {
	var nums []int = []int{1, 2, 3}
	var target int = 4
	var res = combinationSum4(nums, target)
	assert.Equal(t, 7, res)

	nums = []int{9}
	target = 3
	res = combinationSum4(nums, target)
	assert.Equal(t, 0, res)
}
