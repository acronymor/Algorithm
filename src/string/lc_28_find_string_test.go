package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestStrStr1(t *testing.T) {
	var s1 string = "haystack"
	var s2 string = "needle"
	assert.Equal(t, -1, strStr1(s1, s2))

	s1 = "sadbutsad"
	s2 = "sad"
	assert.Equal(t, 0, strStr1(s1, s2))

	s1 = "leetcode"
	s2 = "leeto"
	assert.Equal(t, -1, strStr1(s1, s2))
}

func TestStrStr2(t *testing.T) {
	var s1 string = "haystack"
	var s2 string = "needle"
	assert.Equal(t, -1, strStr2(s1, s2))

	s1 = "sadbutsad"
	s2 = "sad"
	assert.Equal(t, 0, strStr2(s1, s2))

	s1 = "leetcode"
	s2 = "leeto"
	assert.Equal(t, -1, strStr2(s1, s2))
}
