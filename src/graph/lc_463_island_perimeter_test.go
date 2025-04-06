package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIslandPerimeter1(t *testing.T) {
	var grid [][]int = [][]int{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}
	var res int = islandPerimeter1(grid)
	assert.Equal(t, 16, res)

	grid = [][]int{{1}}
	res = islandPerimeter1(grid)
	assert.Equal(t, 4, res)

	grid = [][]int{{1, 0}}
	res = islandPerimeter1(grid)
	assert.Equal(t, 4, res)
}

func TestIslandPerimeter2(t *testing.T) {
	var grid [][]int = [][]int{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}
	var res int = islandPerimeter2(grid)
	assert.Equal(t, 16, res)

	grid = [][]int{{1}}
	res = islandPerimeter2(grid)
	assert.Equal(t, 4, res)

	grid = [][]int{{1, 0}}
	res = islandPerimeter2(grid)
	assert.Equal(t, 4, res)
}
