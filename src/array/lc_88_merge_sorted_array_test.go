package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMergeSortedArray1(t *testing.T) {
	var nums1 []int = []int{1, 2, 3, 0, 0, 0}
	var m int = 3

	var nums2 []int = []int{2, 5, 6}
	var n int = 3

	mergeSortedArray1(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1, 2, 2, 3, 5, 6}, nums1)

	nums1 = []int{1}
	m = 1

	nums2 = []int{}
	n = 0
	mergeSortedArray1(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1}, nums1)

	nums1 = []int{0}
	m = 0
	nums2 = []int{1}
	n = 1
	mergeSortedArray1(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1}, nums1)
}

func TestMergeSortedArray2(t *testing.T) {
	var nums1 []int = []int{1, 2, 3, 0, 0, 0}
	var m int = 3

	var nums2 []int = []int{2, 5, 6}
	var n int = 3

	mergeSortedArray2(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1, 2, 2, 3, 5, 6}, nums1)

	nums1 = []int{1}
	m = 1

	nums2 = []int{}
	n = 0
	mergeSortedArray2(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1}, nums1)

	nums1 = []int{0}
	m = 0
	nums2 = []int{1}
	n = 1
	mergeSortedArray2(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1}, nums1)

	nums1 = []int{2, 0}
	m = 1
	nums2 = []int{1}
	n = 1
	mergeSortedArray2(nums1, m, nums2, n)
	assert.ElementsMatch(t, []int{1, 2}, nums1)
}
