package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestEvalRPN(t *testing.T) {
	var tokens []string = []string{"2", "1", "+", "3", "*"}
	assert.Equal(t, 9, evalRPN(tokens))

	tokens = []string{"4", "13", "5", "/", "+"}
	assert.Equal(t, 6, evalRPN(tokens))

	tokens = []string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}
	assert.Equal(t, 22, evalRPN(tokens))
}
