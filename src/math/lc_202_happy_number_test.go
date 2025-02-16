package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIsHappy(t *testing.T) {
	assert.True(t, isHappy(19))
	assert.False(t, isHappy(2))
}
