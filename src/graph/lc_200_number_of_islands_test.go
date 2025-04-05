package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNumIslands1(t *testing.T) {
	var grid [][]byte = [][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}

	var res = numIslands1(grid)
	assert.Equal(t, 1, res)

	grid = [][]byte{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	}

	res = numIslands1(grid)
	assert.Equal(t, 3, res)
}

func TestNumIslands2(t *testing.T) {
	var grid [][]byte = [][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}

	var res = numIslands2(grid)
	assert.Equal(t, 1, res)

	grid = [][]byte{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	}

	res = numIslands2(grid)
	assert.Equal(t, 3, res)
}

func TestNumIslands3(t *testing.T) {
	var grid [][]byte = [][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}

	var res = numIslands3(grid)
	assert.Equal(t, 1, res)

	grid = [][]byte{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	}

	res = numIslands3(grid)
	assert.Equal(t, 3, res)
}
