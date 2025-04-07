package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLadderLength(t *testing.T) {
	var beginWord string = "hit"
	var endWord string = "cog"
	var wordList []string = []string{"hot", "dot", "dog", "lot", "log", "cog"}
	var res int = ladderLength(beginWord, endWord, wordList)
	assert.Equal(t, 5, res)

	beginWord = "hit"
	endWord = "cog"
	wordList = []string{"hot", "dot", "dog", "lot", "log"}
	res = ladderLength(beginWord, endWord, wordList)
	assert.Equal(t, 0, res)
}
