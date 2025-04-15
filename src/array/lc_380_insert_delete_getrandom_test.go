package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRandomizedSet(t *testing.T) {
	set := Constructor()
	assert.True(t, set.Insert(1))
	assert.False(t, set.Remove(2))
	assert.True(t, set.Insert(2))
	assert.True(t, set.Remove(1))
	assert.False(t, set.Insert(2))
	assert.Equal(t, 2, set.GetRandom())
}
