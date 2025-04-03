package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLargestRectangleArea(t *testing.T) {
	var heights []int = []int{2, 1, 5, 6, 2, 3}
	var res = largestRectangleArea(heights)
	assert.Equal(t, 10, res)

	heights = []int{2, 4}
	res = largestRectangleArea(heights)
	assert.Equal(t, 4, res)
}
