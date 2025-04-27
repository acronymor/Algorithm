package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLongestPalindrome(t *testing.T) {
	var s string = "babad"
	var res string = longestPalindrome(s)
	assert.Equal(t, "bab", res)

	s = "cbbd"
	res = longestPalindrome(s)
	assert.Equal(t, "bb", res)
}
