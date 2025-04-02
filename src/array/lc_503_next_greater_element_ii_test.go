package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNextGreaterElements(t *testing.T) {
	var nums []int = []int{1, 2, 1}
	var res = nextGreaterElements(nums)
	assert.ElementsMatch(t, []int{2, -1, 2}, res)

	nums = []int{1, 2, 3, 4, 3}
	res = nextGreaterElements(nums)
	assert.ElementsMatch(t, []int{2, 3, 4, -1, 4}, res)
}
