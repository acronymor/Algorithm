package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestGenerateMatrix(t *testing.T) {
	var n = 3
	var res [][]int = generateMatrix(n)
	assert.ElementsMatch(t, []int{1, 2, 3}, res[0])
	assert.ElementsMatch(t, []int{8, 9, 4}, res[1])
	assert.ElementsMatch(t, []int{7, 6, 5}, res[2])
}
