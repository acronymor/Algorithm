package tree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNumTrees(t *testing.T) {
	var n int = 3
	var res = numTrees(n)
	assert.Equal(t, 5, res)

	res = numTrees(1)
	assert.Equal(t, 1, res)
}
