package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLengthOfLIS(t *testing.T) {
	var nums []int = []int{10, 9, 2, 5, 3, 7, 101, 18}
	var res = lengthOfLIS(nums)
	assert.Equal(t, 4, res)

	nums = []int{0, 1, 0, 3, 2, 3}
	res = lengthOfLIS(nums)
	assert.Equal(t, 4, res)

	nums = []int{7, 7, 7, 7, 7, 7, 7}
	res = lengthOfLIS(nums)
	assert.Equal(t, 1, res)
}
