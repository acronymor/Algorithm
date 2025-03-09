package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSubsetsWithDup(t *testing.T) {
	var nums []int = []int{1, 2, 2}
	var res [][]int = subsetsWithDup(nums)
	assert.ElementsMatch(t, []int{}, res[0])
	assert.ElementsMatch(t, []int{1}, res[1])
	assert.ElementsMatch(t, []int{1, 2}, res[2])
	assert.ElementsMatch(t, []int{1, 2, 2}, res[3])
	assert.ElementsMatch(t, []int{2}, res[4])
	assert.ElementsMatch(t, []int{2, 2}, res[5])
}
