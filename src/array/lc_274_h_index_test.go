package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestHIndex(t *testing.T) {
	var citations []int = []int{3, 0, 6, 1, 5}
	var res int = hIndex(citations)
	assert.Equal(t, 3, res)

	citations = []int{1, 3, 1}
	res = hIndex(citations)
	assert.Equal(t, 1, res)
}
