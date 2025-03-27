package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCanJump(t *testing.T) {
	var nums []int = []int{2, 3, 1, 1, 4}
	var res = canJump(nums)
	assert.True(t, res)

	nums = []int{3, 2, 1, 0, 4}
	res = canJump(nums)
	assert.False(t, res)

	nums = []int{1, 2}
	res = canJump(nums)
	assert.True(t, res)

	nums = []int{0, 2, 3}
	res = canJump(nums)
	assert.False(t, res)
}
