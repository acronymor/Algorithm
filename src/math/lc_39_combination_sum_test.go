package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCombinationSum(t *testing.T) {
	var candidates []int = []int{2, 3, 6, 7}
	var target int = 7

	var res [][]int = combinationSum(candidates, target)
	assert.ElementsMatch(t, []int{2, 2, 3}, res[0])
	assert.ElementsMatch(t, []int{7}, res[1])

	candidates = []int{2, 3, 5}
	target = 8
	res = combinationSum(candidates, target)
	assert.ElementsMatch(t, []int{2, 2, 2, 2}, res[0])
	assert.ElementsMatch(t, []int{2, 3, 3}, res[1])
	assert.ElementsMatch(t, []int{3, 5}, res[2])

	candidates = []int{8, 7, 4, 3}
	target = 11
	res = combinationSum(candidates, target)
	assert.ElementsMatch(t, []int{3, 4, 4}, res[0])
	assert.ElementsMatch(t, []int{3, 8}, res[1])
	assert.ElementsMatch(t, []int{4, 7}, res[2])
}
