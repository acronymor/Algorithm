package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindContentChildren(t *testing.T) {
	var g []int = []int{1, 2, 3}
	var s []int = []int{1, 1}
	var res int = findContentChildren(g, s)
	assert.Equal(t, 1, res)

	g = []int{1, 2}
	s = []int{1, 2, 3}
	res = findContentChildren(g, s)
	assert.Equal(t, 2, res)

	g = []int{10, 9, 8, 7}
	s = []int{5, 6, 7, 8}
	res = findContentChildren(g, s)
	assert.Equal(t, 2, res)
}
