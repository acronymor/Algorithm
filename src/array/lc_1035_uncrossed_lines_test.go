package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxUncrossedLines(t *testing.T) {
	var nums1 []int = []int{1, 4, 2}
	var nums2 []int = []int{1, 2, 4}

	var res int = maxUncrossedLines(nums1, nums2)
	assert.Equal(t, 2, res)

	nums1 = []int{2, 5, 1, 2, 5}
	nums2 = []int{10, 5, 2, 1, 5, 2}
	res = maxUncrossedLines(nums1, nums2)
	assert.Equal(t, 3, res)

	nums1 = []int{1, 3, 7, 1, 7, 5}
	nums2 = []int{1, 9, 2, 5, 1}
	res = maxUncrossedLines(nums1, nums2)
	assert.Equal(t, 2, res)
}
