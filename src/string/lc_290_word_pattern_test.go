package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestWordPattern(t *testing.T) {
	var pattern string = "abba"
	var s string = "dog cat cat dog"
	assert.True(t, wordPattern(pattern, s))

	pattern = "abba"
	s = "dog cat cat fish"
	assert.False(t, wordPattern(pattern, s))

	pattern = "aaaa"
	s = "dog cat cat dog"
	assert.False(t, wordPattern(pattern, s))
}
