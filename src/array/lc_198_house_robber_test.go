package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRob(t *testing.T) {
	var nums []int = []int{1, 2, 3, 1}
	var res = rob(nums)
	assert.Equal(t, 4, res)

	nums = []int{2, 7, 9, 3, 1}
	res = rob(nums)
	assert.Equal(t, 12, res)
}
