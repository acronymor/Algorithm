package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindRedundantConnection(t *testing.T) {
	var edges = [][]int{{1, 2}, {1, 3}, {2, 3}}
	var res []int = findRedundantConnection(edges)
	assert.ElementsMatch(t, []int{2, 3}, res)

	edges = [][]int{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}
	res = findRedundantConnection(edges)
	assert.ElementsMatch(t, []int{1, 4}, res)
}
