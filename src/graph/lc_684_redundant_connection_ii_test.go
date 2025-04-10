package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindRedundantDirectedConnection(t *testing.T) {
	var edges = [][]int{{1, 2}, {1, 3}, {2, 3}}
	var res []int = findRedundantDirectedConnection(edges)
	assert.ElementsMatch(t, []int{2, 3}, res)

	edges = [][]int{{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}}
	res = findRedundantDirectedConnection(edges)
	assert.ElementsMatch(t, []int{4, 1}, res)

	edges = [][]int{{2, 1}, {3, 1}, {4, 2}, {1, 4}}
	res = findRedundantDirectedConnection(edges)
	assert.ElementsMatch(t, []int{2, 1}, res)
}
