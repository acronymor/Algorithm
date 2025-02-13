package array

/**
 * @brief 螺旋矩阵 II
 *
 * @details
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 * @par 示例
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 * @see [leetcode-59](https://leetcode.cn/problems/spiral-matrix-ii/)
 */

func generateMatrix(n int) [][]int {
	var res [][]int = make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n)
	}

	var m int = n / 2
	var idx int = 1

	for i := 0; i < m; i++ {
		for j := i; j < n-i-1; j++ {
			res[i][j] = idx
			idx++
		}

		for j := i; j < n-i-1; j++ {
			res[j][n-i-1] = idx
			idx++
		}

		for j := n - i - 1; j > i; j-- {
			res[n-i-1][j] = idx
			idx++
		}

		for j := n - i - 1; j > i; j-- {
			res[j][i] = idx
			idx++
		}
	}

	var remain int = n % 2
	if remain != 0 {
		res[m][m] = n * n
	}

	return res
}
