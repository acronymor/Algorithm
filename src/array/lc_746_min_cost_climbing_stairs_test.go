package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMinCostClimbingStairs(t *testing.T) {
	var cost []int = []int{10, 15, 20}
	var res int = minCostClimbingStairs(cost)
	assert.Equal(t, 15, res)

	cost = []int{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}
	res = minCostClimbingStairs(cost)
	assert.Equal(t, 6, res)
}
