package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCombine(t *testing.T) {
	var n = 4
	var k = 2
	var res [][]int = combine(n, k)
	assert.ElementsMatch(t, []int{1, 2}, res[0])
	assert.ElementsMatch(t, []int{1, 3}, res[1])
	assert.ElementsMatch(t, []int{1, 4}, res[2])
}
