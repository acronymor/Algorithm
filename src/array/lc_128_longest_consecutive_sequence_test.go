package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLongestConsecutive(t *testing.T) {
	var nums []int = []int{100, 4, 200, 1, 3, 2}
	assert.Equal(t, 4, longestConsecutive(nums))

	nums = []int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}
	assert.Equal(t, 9, longestConsecutive(nums))

	nums = []int{1, 0, 1, 2}
	assert.Equal(t, 3, longestConsecutive(nums))
}
