package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLetterCombinations(t *testing.T) {
	var digits string = "23"
	var res []string = letterCombinations(digits)
	assert.ElementsMatch(t, []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}, res)

	digits = "2"
	res = letterCombinations(digits)
	assert.ElementsMatch(t, []string{"a", "b", "c"}, res)

	digits = ""
	res = letterCombinations(digits)
	assert.ElementsMatch(t, []string{}, res)
}
