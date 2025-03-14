package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIntegerBreak(t *testing.T) {
	var n int = 2
	var res int = integerBreak(n)
	assert.Equal(t, 1, res)

	n = 10
	res = integerBreak(n)
	assert.Equal(t, 36, res)
}
