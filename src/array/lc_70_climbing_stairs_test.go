package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestClimbStairs(t *testing.T) {
	var n int = 2
	var res int = climbStairs(n)
	assert.Equal(t, 2, res)

	n = 3
	res = climbStairs(n)
	assert.Equal(t, 3, res)
}
