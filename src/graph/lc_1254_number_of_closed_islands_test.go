package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestClosedIsland(t *testing.T) {
	var grid [][]int = [][]int{
		{1, 1, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0, 1, 1, 0},
		{1, 0, 1, 0, 1, 1, 1, 0},
		{1, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 0},
	}
	var res int = closedIsland(grid)
	assert.Equal(t, 2, res)

	grid = [][]int{
		{0, 0, 1, 0, 0},
		{0, 1, 0, 1, 0},
		{0, 1, 1, 1, 0},
	}
	res = closedIsland(grid)
	assert.Equal(t, 1, res)
}
