package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFib(t *testing.T) {
	var n int = 2
	var res int = fib(n)
	assert.Equal(t, 1, res)

	res = fib(3)
	assert.Equal(t, 2, res)

}
