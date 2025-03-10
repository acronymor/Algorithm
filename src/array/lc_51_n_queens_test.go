package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSolveNQueens(t *testing.T) {
	var n int = 4
	var res [][]string = solveNQueens(n)
	assert.ElementsMatch(t, []string{".Q..", "...Q", "Q...", "..Q."}, res[0])
	assert.ElementsMatch(t, []string{"..Q.", "Q...", "...Q", ".Q.."}, res[1])

	n = 1
	res = solveNQueens(n)
	assert.Equal(t, []string{"Q"}, res[0])
}
