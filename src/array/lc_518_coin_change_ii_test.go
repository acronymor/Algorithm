package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestChange1(t *testing.T) {
	var coins []int = []int{1, 2, 5}
	var amount int = 5
	var res = change1(amount, coins)
	assert.Equal(t, 4, res)

	coins = []int{2}
	amount = 3
	res = change1(amount, coins)
	assert.Equal(t, 0, res)

	coins = []int{10}
	amount = 10
	res = change1(amount, coins)
	assert.Equal(t, 1, res)
}

func TestChange2(t *testing.T) {
	var coins []int = []int{1, 2, 5}
	var amount int = 5
	var res = change2(amount, coins)
	assert.Equal(t, 4, res)

	coins = []int{2}
	amount = 3
	res = change2(amount, coins)
	assert.Equal(t, 0, res)

	coins = []int{10}
	amount = 10
	res = change2(amount, coins)
	assert.Equal(t, 1, res)

}
