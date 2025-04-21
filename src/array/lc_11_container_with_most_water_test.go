package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxArea(t *testing.T) {
	var height []int = []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	var res = maxArea(height)
	assert.Equal(t, 49, res)

	height = []int{1, 1}
	res = maxArea(height)
	assert.Equal(t, 1, res)
}
