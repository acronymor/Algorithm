package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCoinChange(t *testing.T) {
	var coins []int = []int{1, 2, 5}
	var amount int = 11
	var res int = coinChange1(coins, amount)
	assert.Equal(t, 3, res)

	coins = []int{2}
	amount = 3
	res = coinChange1(coins, amount)
	assert.Equal(t, -1, res)

	coins = []int{1}
	amount = 0
	res = coinChange1(coins, amount)
	assert.Equal(t, 0, res)

	coins = []int{1}
	amount = 2
	res = coinChange1(coins, amount)
	assert.Equal(t, 2, res)
}

func TestCoinChange2(t *testing.T) {
	var coins []int = []int{1, 2, 5}
	var amount int = 11
	var res int = coinChange2(coins, amount)
	assert.Equal(t, 3, res)

	coins = []int{2}
	amount = 3
	res = coinChange2(coins, amount)
	assert.Equal(t, -1, res)

	coins = []int{1}
	amount = 0
	res = coinChange2(coins, amount)
	assert.Equal(t, 0, res)

	coins = []int{1}
	amount = 2
	res = coinChange2(coins, amount)
	assert.Equal(t, 2, res)
}
