package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindMaxForm(t *testing.T) {
	var strs []string = []string{"10", "0001", "111001", "1", "0"}
	var m = 5
	var n = 3
	var res = findMaxForm(strs, m, n)
	assert.Equal(t, 4, res)

	strs = []string{"10", "0", "1"}
	m, n = 1, 1
	res = findMaxForm(strs, m, n)
	assert.Equal(t, 2, res)
}
