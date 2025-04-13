package algo

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSortArray(t *testing.T) {
	var target []int = []int{1, 2, 3, 5}

	var nums []int = []int{5, 2, 3, 1}
	assert.ElementsMatch(t, target, bubbleSort(nums))

	nums = []int{5, 2, 3, 1}
	assert.ElementsMatch(t, target, selectSort(nums))

	nums = []int{5, 2, 3, 1}
	assert.ElementsMatch(t, target, insertSort(nums))

	nums = []int{5, 2, 3, 1}
	assert.ElementsMatch(t, target, quickSort(nums))

	nums = []int{5, 2, 3, 1}
	assert.ElementsMatch(t, target, heapSort(nums))
}
