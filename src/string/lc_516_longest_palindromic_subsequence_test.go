package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLongestPalindromeSubseq(t *testing.T) {
	var s string = "bbbab"
	var res = longestPalindromeSubseq(s)
	assert.Equal(t, 4, res)

	s = "cbbd"
	res = longestPalindromeSubseq(s)
	assert.Equal(t, 2, res)
}
