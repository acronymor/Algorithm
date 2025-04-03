package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestTrap(t *testing.T) {
	var height []int = []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
	var res int = trap(height)
	assert.Equal(t, 6, res)

	height = []int{4, 2, 0, 3, 2, 5}
	res = trap(height)
	assert.Equal(t, 9, res)
}
