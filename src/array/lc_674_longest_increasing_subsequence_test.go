package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindLengthOfLCIS(t *testing.T) {
	var nums []int = []int{1, 3, 5, 4, 7}
	var res = findLengthOfLCIS(nums)
	assert.Equal(t, 3, res)

	nums = []int{2, 2, 2, 2, 2}
	res = findLengthOfLCIS(nums)
	assert.Equal(t, 1, res)
}
