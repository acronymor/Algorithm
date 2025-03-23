package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxProfitVI(t *testing.T) {
	var prices []int = []int{1, 3, 2, 8, 4, 9}
	var fee int = 2
	var res int = maxProfitVI(prices, fee)
	assert.Equal(t, 8, res)

	prices = []int{1, 3, 7, 5, 10, 3}
	fee = 3
	res = maxProfitVI(prices, fee)
	assert.Equal(t, 6, res)
}
