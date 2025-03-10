package array

import "strings"

/**
 * @brief N 皇后
 *
 * @details
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 * @par 示例
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 * @see [leetcode-51](https://leetcode.cn/problems/n-queens/)
 */

func solveNQueens(n int) [][]string {
	check := func(board [][]string, row int, col int) bool {
		for i := 0; i < row; i++ {
			if board[i][col] == "Q" {
				return false
			}
		}

		for i, j := row-1, col-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
			if board[i][j] == "Q" {
				return false
			}
		}

		for i, j := row-1, col+1; i >= 0 && j < n; i, j = i-1, j+1 {
			if board[i][j] == "Q" {
				return false
			}
		}

		return true
	}

	var res [][]string
	var ans [][]string = make([][]string, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]string, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			ans[i][j] = "."
		}
	}

	var backtrace func(row int)
	backtrace = func(row int) {
		if row == n {
			tmp := make([]string, len(ans))
			for i, line := range ans {
				tmp[i] = strings.Join(line, "")
			}
			res = append(res, tmp)
			return
		}

		for col := 0; col < n; col++ {
			if !check(ans, row, col) {
				continue
			}

			ans[row][col] = "Q"
			backtrace(row + 1)
			ans[row][col] = "."
		}
	}

	backtrace(0)
	return res
}
