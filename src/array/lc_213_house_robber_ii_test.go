package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRobii(t *testing.T) {
	var nums []int = []int{2, 3, 2}
	var res = robii(nums)
	assert.Equal(t, 3, res)

	nums = []int{1, 2, 3, 1}
	res = robii(nums)
	assert.Equal(t, 4, res)

	nums = []int{1, 2, 3}
	res = robii(nums)
	assert.Equal(t, 3, res)

	nums = []int{0, 0}
	res = robii(nums)
	assert.Equal(t, 0, res)

	nums = []int{0}
	res = robii(nums)
	assert.Equal(t, 0, res)
}
