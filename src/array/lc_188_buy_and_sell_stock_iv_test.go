package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxProfitIV(t *testing.T) {
	var price []int = []int{2, 4, 1}
	var k int = 2
	var res int = maxProfitIV(price, k)
	assert.Equal(t, 2, res)

	price = []int{3, 2, 6, 5, 0, 3}
	k = 2
	res = maxProfitIV(price, k)
	assert.Equal(t, 7, res)
}
