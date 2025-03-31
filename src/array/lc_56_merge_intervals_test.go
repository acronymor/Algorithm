package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMerge(t *testing.T) {
	var intervals [][]int = [][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}}
	var res [][]int = merge(intervals)
	assert.ElementsMatch(t, []int{1, 6}, res[0])
	assert.ElementsMatch(t, []int{8, 10}, res[1])
	assert.ElementsMatch(t, []int{15, 18}, res[2])

	intervals = [][]int{{1, 4}, {4, 5}}
	res = merge(intervals)
	assert.ElementsMatch(t, []int{1, 5}, res[0])
}
