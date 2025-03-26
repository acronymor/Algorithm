package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCountSubstrings1(t *testing.T) {
	var s string = "abc"
	var res int = countSubstrings1(s)
	assert.Equal(t, 3, res)

	s = "aaa"
	res = countSubstrings1(s)
	assert.Equal(t, 6, res)
}

func TestCountSubstrings2(t *testing.T) {
	var s string = "abc"
	var res int = countSubstrings2(s)
	assert.Equal(t, 3, res)

	s = "aaa"
	res = countSubstrings2(s)
	assert.Equal(t, 6, res)
}
