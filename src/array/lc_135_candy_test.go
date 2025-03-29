package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCandy(t *testing.T) {
	var ratings []int = []int{1, 0, 2}

	var res int = candy(ratings)
	assert.Equal(t, 5, res)

	ratings = []int{1, 2, 2}
	res = candy(ratings)
	assert.Equal(t, 4, res)
}
