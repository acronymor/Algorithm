package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNumSquares(t *testing.T) {
	assert.Equal(t, 3, numSquares(12))
	assert.Equal(t, 2, numSquares(13))
}
