package queue

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMyStack(t *testing.T) {
	var stack MyStack = Constructor()
	stack.Push(1)
	stack.Push(2)
	var res = stack.Top()
	assert.Equal(t, 2, res)
	stack.Pop()

	res = stack.Top()
	assert.Equal(t, 1, res)

	stack.Pop()
	assert.True(t, stack.Empty())
}
