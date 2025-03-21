package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxProfitII(t *testing.T) {
	var price []int = []int{7, 1, 5, 3, 6, 4}
	var res int = maxProfitII(price)
	assert.Equal(t, 7, res)

	price = []int{1, 2, 3, 4, 5}
	res = maxProfitII(price)
	assert.Equal(t, 4, res)

	price = []int{7, 6, 4, 3, 1}
	res = maxProfitII(price)
	assert.Equal(t, 0, res)
}
