package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCombinationSum2(t *testing.T) {
	var candidates []int = []int{10, 1, 2, 7, 6, 1, 5}
	var target int = 8

	var res [][]int = combinationSum2(candidates, target)
	assert.ElementsMatch(t, []int{1, 1, 6}, res[0])
	assert.ElementsMatch(t, []int{1, 2, 5}, res[1])
	assert.ElementsMatch(t, []int{1, 7}, res[2])
	assert.ElementsMatch(t, []int{2, 6}, res[3])

	candidates = []int{2, 5, 2, 1, 2}
	target = 5
	res = combinationSum2(candidates, target)
	assert.ElementsMatch(t, []int{1, 2, 2}, res[0])
	assert.ElementsMatch(t, []int{5}, res[1])
}
