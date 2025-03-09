package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPermuteUnique(t *testing.T) {
	var nums []int = []int{1, 1, 2}
	var res [][]int = permuteUnique(nums)
	assert.ElementsMatch(t, []int{1, 1, 2}, res[0])
	assert.ElementsMatch(t, []int{1, 2, 1}, res[1])
}
