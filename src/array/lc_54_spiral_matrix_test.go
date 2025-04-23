package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSpiralOrder(t *testing.T) {
	var matrix [][]int = [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	var target []int = []int{1, 2, 3, 6, 9, 8, 7, 4, 5}
	assert.ElementsMatch(t, target, spiralOrder(matrix))

	matrix = [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	target = []int{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}
	assert.ElementsMatch(t, target, spiralOrder(matrix))
}
