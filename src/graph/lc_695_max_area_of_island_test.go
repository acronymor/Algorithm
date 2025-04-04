package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxAreaOfIsland1(t *testing.T) {
	var grid [][]int = [][]int{
		{1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}

	var res = maxAreaOfIsland1(grid)
	assert.Equal(t, 9, res)

	grid = [][]int{
		{1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 1},
	}

	res = maxAreaOfIsland1(grid)
	assert.Equal(t, 4, res)
}

func TestMaxAreaOfIsland2(t *testing.T) {
	var grid [][]int = [][]int{
		{1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}

	var res = maxAreaOfIsland2(grid)
	assert.Equal(t, 9, res)

	grid = [][]int{
		{1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 1},
	}

	res = maxAreaOfIsland2(grid)
	assert.Equal(t, 4, res)
}
