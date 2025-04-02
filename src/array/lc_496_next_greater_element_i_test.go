package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNextGreaterElement(t *testing.T) {
	var nums1 []int = []int{4, 1, 2}
	var nums2 []int = []int{1, 3, 4, 2}
	var res []int = nextGreaterElement(nums1, nums2)
	assert.ElementsMatch(t, []int{-1, 3, -1}, res)

	nums1 = []int{2, 4}
	nums2 = []int{1, 2, 3, 4}
	res = nextGreaterElement(nums1, nums2)
	assert.ElementsMatch(t, []int{3, -1}, res)
}
