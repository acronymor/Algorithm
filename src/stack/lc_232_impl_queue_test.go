package stack

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMyQueue(t *testing.T) {
	var queue MyQueue = Constructor()
	queue.Push(1)
	queue.Push(2)
	var res = queue.Peek()
	assert.Equal(t, 1, res)
	queue.Pop()

	res = queue.Peek()
	assert.Equal(t, 2, res)

	queue.Pop()
	assert.True(t, queue.Empty())
}
