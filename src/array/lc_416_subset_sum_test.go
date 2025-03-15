package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCanPartition(t *testing.T) {
	var nums []int = []int{1, 5, 11, 5}
	assert.True(t, canPartition(nums))

	nums = []int{1, 2, 3, 5}
	assert.False(t, canPartition(nums))

}
