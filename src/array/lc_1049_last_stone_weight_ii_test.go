package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLastStoneWeightII(t *testing.T) {
	var stones []int = []int{2, 7, 4, 1, 8, 1}
	var res int = lastStoneWeightII(stones)
	assert.Equal(t, 1, res)

	stones = []int{31, 26, 33, 21, 40}
	res = lastStoneWeightII(stones)
	assert.Equal(t, 5, res)
}
