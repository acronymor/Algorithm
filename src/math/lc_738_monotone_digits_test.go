package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMonotoneIncreasingDigits(t *testing.T) {
	var n int = 10
	var res = monotoneIncreasingDigits(n)
	assert.Equal(t, 9, res)

	n = 1234
	res = monotoneIncreasingDigits(n)
	assert.Equal(t, 1234, res)

	n = 332
	res = monotoneIncreasingDigits(n)
	assert.Equal(t, 299, res)

	n = 100
	res = monotoneIncreasingDigits(n)
	assert.Equal(t, 99, res)
}
