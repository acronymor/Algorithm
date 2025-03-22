package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxProfitIII(t *testing.T) {
	var price []int = []int{3, 3, 5, 0, 0, 3, 1, 4}
	var res int = maxProfitIII(price)
	assert.Equal(t, 6, res)

	price = []int{1, 2, 3, 4, 5}
	res = maxProfitIII(price)
	assert.Equal(t, 4, res)

	price = []int{7, 6, 4, 3, 1}
	res = maxProfitIII(price)
	assert.Equal(t, 0, res)
}
