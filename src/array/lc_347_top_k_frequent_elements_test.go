package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestTopKFrequent(t *testing.T) {
	var nums []int = []int{1, 1, 1, 2, 2, 3}
	var k int = 2
	var res []int = topKFrequent(nums, k)
	assert.ElementsMatch(t, []int{1, 2}, res)

	nums = []int{1}
	k = 1
	res = topKFrequent(nums, k)
	assert.ElementsMatch(t, []int{1}, res)
}
