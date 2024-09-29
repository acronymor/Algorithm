package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRemoveDuplicates(t *testing.T) {
	var nums []int = []int{1, 1, 2}
	var res int = removeDuplicates(nums)
	assert.Equal(t, 2, res)

	nums = []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
	res = removeDuplicates(nums)
	assert.Equal(t, 5, res)
}
