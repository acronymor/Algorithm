package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestProductExceptSelf(t *testing.T) {
	var nums []int = []int{1, 2, 3, 4}
	var res []int = productExceptSelf(nums)
	var target []int = []int{24, 12, 8, 6}
	assert.ElementsMatch(t, target, res)

	nums = []int{-1, 1, 0, -3, 3}
	res = productExceptSelf(nums)
	target = []int{0, 0, 9, 0, 0}
	assert.ElementsMatch(t, target, res)
}
