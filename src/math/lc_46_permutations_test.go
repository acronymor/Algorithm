package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPermute(t *testing.T) {
	var nums []int = []int{1, 2, 3}
	var res [][]int = permute(nums)
	assert.ElementsMatch(t, []int{1, 2, 3}, res[0])
	assert.ElementsMatch(t, []int{1, 3, 2}, res[1])
}
