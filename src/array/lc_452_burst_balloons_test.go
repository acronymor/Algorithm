package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindMinArrowShots(t *testing.T) {
	var points [][]int = [][]int{{10, 16}, {2, 8}, {1, 6}, {7, 12}}
	assert.Equal(t, 2, findMinArrowShots(points))

	points = [][]int{{1, 2}, {3, 4}, {5, 6}, {7, 8}}
	assert.Equal(t, 4, findMinArrowShots(points))

	points = [][]int{{1, 2}, {2, 3}, {3, 4}, {4, 5}}
	assert.Equal(t, 2, findMinArrowShots(points))
}
