package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIsAnagram(t *testing.T) {
	var s1 string = "anagram"
	var s2 string = "nagaram"
	assert.True(t, isAnagram(s1, s2))

	s1 = "rat"
	s2 = "car"
	assert.False(t, isAnagram(s1, s2))
}
