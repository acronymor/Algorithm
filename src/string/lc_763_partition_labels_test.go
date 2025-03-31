package string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestPartitionLabels(t *testing.T) {
	var s string = "ababcbacadefegdehijhklij"
	var res []int = partitionLabels(s)
	assert.ElementsMatch(t, []int{7, 9, 8}, res)

	s = "eccbbbbdec"
	res = partitionLabels(s)
	assert.ElementsMatch(t, []int{10}, res)
}
