package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLemonadeChange(t *testing.T) {
	var bills []int = []int{5, 5, 5, 10, 20}
	assert.True(t, lemonadeChange(bills))

	bills = []int{5, 5, 10, 10, 20}
	assert.False(t, lemonadeChange(bills))

	bills = []int{5, 5, 5, 10, 5, 5, 10, 20, 20, 20}
	assert.False(t, lemonadeChange(bills))
}
