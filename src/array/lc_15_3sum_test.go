package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestThreeSum1(t *testing.T) {
	var nums []int
	var res [][]int

	nums = []int{-1, 0, 1, 2, -1, -4}
	res = threeSum1(nums)
	assert.ElementsMatch(t, res[0], []int{-1, 0, 1})
	assert.ElementsMatch(t, res[1], []int{-1, -1, 2})
}

func TestThreeSum2(t *testing.T) {
	var nums []int
	var res [][]int

	nums = []int{-1, 0, 1, 2, -1, -4}
	res = threeSum2(nums)
	assert.ElementsMatch(t, res[0], []int{-1, -1, 2})
	assert.ElementsMatch(t, res[1], []int{-1, 0, 1})
}
