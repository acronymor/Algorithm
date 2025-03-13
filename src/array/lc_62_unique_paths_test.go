package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestUniquePaths(t *testing.T) {
	var m = 3
	var n = 7
	var res = uniquePaths(m, n)
	assert.Equal(t, 28, res)

	m = 3
	n = 2
	res = uniquePaths(m, n)
	assert.Equal(t, 3, res)
}
