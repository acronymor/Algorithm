package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSubsets(t *testing.T) {
	var nums []int = []int{1, 2, 3}
	var res [][]int = subsets(nums)

	assert.ElementsMatch(t, []int{}, res[0])
	assert.ElementsMatch(t, []int{1}, res[1])
	assert.ElementsMatch(t, []int{1, 2}, res[2])
	assert.ElementsMatch(t, []int{1, 2, 3}, res[3])
}
