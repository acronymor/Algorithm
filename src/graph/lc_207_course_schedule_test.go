package graph

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCanFinish(t *testing.T) {
	var numCourses int = 2
	var prerequisites [][]int = [][]int{{1, 0}}
	assert.True(t, canFinish(numCourses, prerequisites))

	numCourses = 2
	prerequisites = [][]int{{1, 0}, {0, 1}}
	assert.False(t, canFinish(numCourses, prerequisites))
}
