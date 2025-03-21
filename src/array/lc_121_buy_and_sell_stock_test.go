package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMaxProfit(t *testing.T) {
	var price []int = []int{7, 1, 5, 3, 6, 4}
	var res int = maxProfit(price)
	assert.Equal(t, 5, res)

	price = []int{7, 6, 4, 3, 1}
	res = maxProfit(price)
	assert.Equal(t, 0, res)
}
