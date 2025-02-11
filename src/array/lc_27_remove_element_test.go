package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRemoveElement1(t *testing.T) {
	var nums []int = []int{3, 2, 2, 3}
	var target = 3
	var res int = removeElement1(nums, target)
	assert.Equal(t, 2, res)

	nums = []int{0, 1, 2, 2, 3, 0, 4, 2}
	target = 2
	res = removeElement1(nums, target)
	assert.Equal(t, 5, res)
}

func TestRemoveElement2(t *testing.T) {
	var nums []int = []int{3, 2, 2, 3}
	var target = 3
	var res int = removeElement2(nums, target)
	assert.Equal(t, 2, res)

	nums = []int{0, 1, 2, 2, 3, 0, 4, 2}
	target = 2
	res = removeElement2(nums, target)
	assert.Equal(t, 5, res)
}
