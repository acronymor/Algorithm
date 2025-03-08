package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPartition(t *testing.T) {
	var s string = "aab"
	var res [][]string = partition(s)
	assert.ElementsMatch(t, []string{"a", "a", "b"}, res[0])
	assert.ElementsMatch(t, []string{"aa", "b"}, res[1])

	s = "a"
	res = partition(s)
	assert.ElementsMatch(t, []string{"a"}, res[0])
}
