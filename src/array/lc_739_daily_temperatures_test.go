package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestDailyTemperatures(t *testing.T) {
	var temp []int = []int{73, 74, 75, 71, 69, 72, 76, 73}
	var res []int = dailyTemperatures(temp)
	assert.ElementsMatch(t, []int{1, 1, 4, 2, 1, 1, 0, 0}, res)

	temp = []int{30, 40, 50, 60}
	res = dailyTemperatures(temp)
	assert.ElementsMatch(t, []int{1, 1, 1, 0}, res)

	temp = []int{30, 60, 90}
	res = dailyTemperatures(temp)
	assert.ElementsMatch(t, []int{1, 1, 0}, res)
}
