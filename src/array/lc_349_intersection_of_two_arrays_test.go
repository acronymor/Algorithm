package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIntersection(t *testing.T) {
	var nums1 []int = []int{1, 2, 2, 1}
	var nums2 []int = []int{2, 2}
	assert.ElementsMatch(t, []int{2}, intersection(nums1, nums2))

	nums1 = []int{4, 9, 5}
	nums2 = []int{9, 4, 9, 8, 4}
	assert.ElementsMatch(t, []int{4, 9}, intersection(nums1, nums2))
}
