package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestUniquePathsWithObstacles(t *testing.T) {
	var grid [][]int = [][]int{
		[]int{0, 0, 0},
		[]int{0, 1, 0},
		[]int{0, 0, 0},
	}
	var res int = uniquePathsWithObstacles(grid)
	assert.Equal(t, 2, res)

	grid = [][]int{
		[]int{0, 1},
		[]int{0, 0},
	}
	res = uniquePathsWithObstacles(grid)
	assert.Equal(t, 1, res)
}
