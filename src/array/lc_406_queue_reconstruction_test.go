package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestReconstructQueue(t *testing.T) {
	var people [][]int = [][]int{[]int{7, 0}, []int{4, 4}, []int{7, 1}, []int{5, 0}, []int{6, 1}, []int{5, 2}}
	var res [][]int = reconstructQueue(people)
	assert.ElementsMatch(t, []int{5, 0}, res[0])
	assert.ElementsMatch(t, []int{7, 0}, res[1])
	assert.ElementsMatch(t, []int{5, 2}, res[2])
	assert.ElementsMatch(t, []int{6, 1}, res[3])
	assert.ElementsMatch(t, []int{4, 4}, res[4])
	assert.ElementsMatch(t, []int{7, 1}, res[5])
}
