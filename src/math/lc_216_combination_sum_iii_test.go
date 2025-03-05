package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCombinationSum3(t *testing.T) {
	var res [][]int = combinationSum3(7, 3)
	assert.ElementsMatch(t, []int{1, 2, 4}, res[0])

	res = combinationSum3(9, 3)
	assert.ElementsMatch(t, []int{1, 2, 6}, res[0])
	assert.ElementsMatch(t, []int{1, 3, 5}, res[1])
}
