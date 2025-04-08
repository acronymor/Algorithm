package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestValidPath1(t *testing.T) {
	var n int = 3
	var edges [][]int = [][]int{{0, 1}, {1, 2}, {2, 0}}
	var res bool = validPath1(n, edges, 0, 2)
	assert.True(t, res)

	n = 6
	edges = [][]int{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}
	res = validPath1(n, edges, 0, 5)
	assert.False(t, res)

	n = 10
	edges = [][]int{{0, 7}, {0, 8}, {6, 1}, {2, 0}, {0, 4}, {5, 8}, {4, 7}, {1, 3}, {3, 5}, {6, 5}}
	res = validPath1(n, edges, 7, 5)
	assert.True(t, res)
}

func TestValidPath2(t *testing.T) {
	var n int = 3
	var edges [][]int = [][]int{{0, 1}, {1, 2}, {2, 0}}
	var res bool = validPath2(n, edges, 0, 2)
	assert.True(t, res)

	n = 6
	edges = [][]int{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}
	res = validPath2(n, edges, 0, 5)
	assert.False(t, res)

	n = 10
	edges = [][]int{{0, 7}, {0, 8}, {6, 1}, {2, 0}, {0, 4}, {5, 8}, {4, 7}, {1, 3}, {3, 5}, {6, 5}}
	res = validPath2(n, edges, 7, 5)
	assert.True(t, res)
}

func TestValidPath3(t *testing.T) {
	var n int = 3
	var edges [][]int = [][]int{{0, 1}, {1, 2}, {2, 0}}
	var res bool = validPath3(n, edges, 0, 2)
	assert.True(t, res)

	n = 6
	edges = [][]int{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}
	res = validPath3(n, edges, 0, 5)
	assert.False(t, res)

	n = 10
	edges = [][]int{{0, 7}, {0, 8}, {6, 1}, {2, 0}, {0, 4}, {5, 8}, {4, 7}, {1, 3}, {3, 5}, {6, 5}}
	res = validPath3(n, edges, 7, 5)
	assert.True(t, res)
}
