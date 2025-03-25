package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNumDistinct(tt *testing.T) {
	var s string = "rabbbit"
	var t string = "rabbit"
	var res int = numDistinct(s, t)
	assert.Equal(tt, 3, res)

	s = "babgbag"
	t = "bag"
	res = numDistinct(s, t)
	assert.Equal(tt, 5, res)
}
