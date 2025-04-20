package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestTwoSumII(t *testing.T) {
	var nums []int = []int{2, 7, 11, 15}
	var target = 9
	assert.ElementsMatch(t, []int{1, 2}, twoSumII(nums, target))

	nums = []int{2, 3, 4}
	target = 6
	assert.ElementsMatch(t, []int{1, 3}, twoSumII(nums, target))
}
