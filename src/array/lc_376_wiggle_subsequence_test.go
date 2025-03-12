package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestWiggleMaxLength1(t *testing.T) {
	var nums []int = []int{1, 7, 4, 9, 2, 5}
	var res int = wiggleMaxLength1(nums)
	assert.Equal(t, 6, res)

	nums = []int{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}
	res = wiggleMaxLength1(nums)
	assert.Equal(t, 7, res)
}

func TestWiggleMaxLength2(t *testing.T) {
	var nums []int = []int{1, 7, 4, 9, 2, 5}
	var res int = wiggleMaxLength2(nums)
	assert.Equal(t, 6, res)

	nums = []int{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}
	res = wiggleMaxLength2(nums)
	assert.Equal(t, 7, res)
}
