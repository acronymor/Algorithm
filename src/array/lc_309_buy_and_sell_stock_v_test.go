package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxProfitV(t *testing.T) {
	var prices []int = []int{1, 2, 3, 0, 2}
	var res int = maxProfitV(prices)
	assert.Equal(t, 3, res)

	prices = []int{1}
	res = maxProfitV(prices)
	assert.Equal(t, 0, res)

}
