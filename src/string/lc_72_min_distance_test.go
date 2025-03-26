package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMinDistance(t *testing.T) {
	var word1 string = "horse"
	var word2 string = "ros"
	var res int = minDistance(word1, word2)
	assert.Equal(t, 3, res)

	word1 = "intention"
	word2 = "execution"
	res = minDistance(word1, word2)
	assert.Equal(t, 5, res)

	word1 = ""
	word2 = "a"
	res = minDistance(word1, word2)
	assert.Equal(t, 1, res)
}
