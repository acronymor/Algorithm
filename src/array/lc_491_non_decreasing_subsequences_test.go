package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindSubsequences(t *testing.T) {
	var nums []int = []int{4, 6, 7, 7}
	var res [][]int = findSubsequences(nums)

	assert.ElementsMatch(t, []int{4, 6}, res[0])
	assert.ElementsMatch(t, []int{4, 6, 7}, res[1])
	assert.ElementsMatch(t, []int{4, 6, 7, 7}, res[2])

	nums = []int{4, 4, 3, 2, 1}
	res = findSubsequences(nums)
	assert.ElementsMatch(t, []int{4, 4}, res[0])
}
