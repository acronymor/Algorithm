package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLargestIsland(t *testing.T) {
	var grid [][]int = [][]int{{1, 0}, {0, 1}}
	var res int = largestIsland(grid)
	assert.Equal(t, 3, res)

	grid = [][]int{{1, 1}, {1, 0}}
	res = largestIsland(grid)
	assert.Equal(t, 4, res)

	grid = [][]int{{1, 1}, {1, 1}}
	res = largestIsland(grid)
	assert.Equal(t, 4, res)

	grid = [][]int{
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{1, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 1, 1, 1, 1, 0, 0},
	}
	res = largestIsland(grid)
	assert.Equal(t, 18, res)
}
