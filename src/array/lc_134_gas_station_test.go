package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCanCompleteCircuit1(t *testing.T) {
	var gas []int = []int{1, 2, 3, 4, 5}
	var cost []int = []int{3, 4, 5, 1, 2}
	var res = canCompleteCircuit1(gas, cost)
	assert.Equal(t, 3, res)

	gas = []int{2, 3, 4}
	cost = []int{3, 4, 3}
	res = canCompleteCircuit1(gas, cost)
	assert.Equal(t, -1, res)
}

func TestCanCompleteCircuit2(t *testing.T) {
	var gas []int = []int{1, 2, 3, 4, 5}
	var cost []int = []int{3, 4, 5, 1, 2}
	var res = canCompleteCircuit2(gas, cost)
	assert.Equal(t, 3, res)

	gas = []int{2, 3, 4}
	cost = []int{3, 4, 3}
	res = canCompleteCircuit2(gas, cost)
	assert.Equal(t, -1, res)
}
