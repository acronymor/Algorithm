package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIsValid(t *testing.T) {
	assert.True(t, isValid("()"))
	assert.True(t, isValid("()[]{}"))
	assert.False(t, isValid("(]"))
	assert.False(t, isValid("]"))
	assert.False(t, isValid("(])"))
}
