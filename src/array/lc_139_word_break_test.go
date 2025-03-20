package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestWordBreak(t *testing.T) {
	var s string = "leetcode"
	var wordDict []string = []string{"leet", "code"}
	assert.True(t, wordBreak(s, wordDict))

	s = "applepenapple"
	wordDict = []string{"apple", "pen"}
	assert.True(t, wordBreak(s, wordDict))

	s = "catsandog"
	wordDict = []string{"cats", "dog", "sand", "and", "cat"}
	assert.False(t, wordBreak(s, wordDict))
}
