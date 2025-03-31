package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestEraseOverlapIntervals(t *testing.T) {
	var intervals [][]int = [][]int{{1, 2}, {2, 3}, {3, 4}, {1, 3}}
	var res int = eraseOverlapIntervals(intervals)
	assert.Equal(t, 1, res)

	intervals = [][]int{{1, 2}, {1, 2}, {1, 2}}
	res = eraseOverlapIntervals(intervals)
	assert.Equal(t, 2, res)

	intervals = [][]int{{1, 2}, {2, 3}}
	res = eraseOverlapIntervals(intervals)
	assert.Equal(t, 0, res)
}
