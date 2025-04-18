package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestReverseWords(t *testing.T) {
	var s string = "the sky is blue"
	var target = "blue is sky the"
	assert.Equal(t, target, reverseWords(s))

	s = "  hello world  "
	target = "world hello"
	assert.Equal(t, target, reverseWords(s))

	s = "a good   example"
	target = "example good a"
	assert.Equal(t, target, reverseWords(s))
}
