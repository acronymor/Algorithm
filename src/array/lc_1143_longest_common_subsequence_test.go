package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLongestCommonSubsequence(t *testing.T) {
	var text1 string = "abcde"
	var text2 string = "ace"
	var res int = longestCommonSubsequence(text1, text2)
	assert.Equal(t, 3, res)

	text1 = "abc"
	text2 = "abc"
	res = longestCommonSubsequence(text1, text2)
	assert.Equal(t, 3, res)

	text1 = "abc"
	text2 = "def"
	res = longestCommonSubsequence(text1, text2)
	assert.Equal(t, 0, res)
}
