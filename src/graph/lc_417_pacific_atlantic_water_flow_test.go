package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPacificAtlantic(t *testing.T) {
	var heights [][]int = [][]int{
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4},
	}

	var res = pacificAtlantic(heights)
	assert.ElementsMatch(t, []int{0, 4}, res[0])
	assert.ElementsMatch(t, []int{1, 3}, res[1])
	assert.ElementsMatch(t, []int{1, 4}, res[2])
	assert.ElementsMatch(t, []int{2, 2}, res[3])
	assert.ElementsMatch(t, []int{3, 0}, res[4])
	assert.ElementsMatch(t, []int{3, 1}, res[5])
	assert.ElementsMatch(t, []int{4, 0}, res[6])

	heights = [][]int{{2, 1}, {1, 2}}
	res = pacificAtlantic(heights)
	assert.ElementsMatch(t, []int{0, 0}, res[0])
	assert.ElementsMatch(t, []int{0, 1}, res[1])
	assert.ElementsMatch(t, []int{1, 0}, res[2])
	assert.ElementsMatch(t, []int{1, 1}, res[3])
}
