package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindLength(t *testing.T) {
	var nums1 []int = []int{1, 2, 3, 2, 1}
	var nums2 []int = []int{3, 2, 1, 4, 7}
	var res = findLength(nums1, nums2)
	assert.Equal(t, 3, res)

	nums1 = []int{0, 0, 0, 0, 0}
	nums2 = []int{0, 0, 0, 0, 0}
	res = findLength(nums1, nums2)
	assert.Equal(t, 5, res)
}
