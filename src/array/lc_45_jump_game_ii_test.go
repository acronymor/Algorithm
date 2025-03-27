package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestJump(t *testing.T) {
	var nums []int = []int{2, 3, 1, 1, 4}
	var res = jump(nums)
	assert.Equal(t, 2, res)

	nums = []int{2, 3, 0, 1, 4}
	res = jump(nums)
	assert.Equal(t, 2, res)
}
