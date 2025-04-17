package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLongestCommonPrefix(t *testing.T) {
	var strs []string = []string{"flower", "flow", "flight"}
	assert.Equal(t, "fl", longestCommonPrefix(strs))

	strs = []string{"dog", "racecar", "car"}
	assert.Equal(t, "", longestCommonPrefix(strs))

	strs = []string{"a"}
	assert.Equal(t, "a", longestCommonPrefix(strs))

	strs = []string{"flower", "flower", "flower", "flower"}
	assert.Equal(t, "flower", longestCommonPrefix(strs))
}
