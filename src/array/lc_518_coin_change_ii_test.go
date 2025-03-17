package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestChange(t *testing.T) {
	var coins []int = []int{1, 2, 5}
	var amount int = 5
	var res = change(amount, coins)
	assert.Equal(t, 4, res)

	coins = []int{2}
	amount = 3
	res = change(amount, coins)
	assert.Equal(t, 0, res)

	coins = []int{10}
	amount = 10
	res = change(amount, coins)
	assert.Equal(t, 1, res)

}
