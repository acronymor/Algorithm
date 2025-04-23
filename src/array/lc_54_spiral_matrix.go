package array

/**
 * @brief 螺旋矩阵
 *
 * @details
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 *
 * @par 示例
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 * @see [leetcode-54](https://leetcode.cn/problems/spiral-matrix/)
 */

func spiralOrder(matrix [][]int) []int {
	up, down := 0, len(matrix)-1
	left, right := 0, len(matrix[0])-1

	var res []int = make([]int, len(matrix)*len(matrix[0]))
	var k = 0
	for {
		for j := left; j <= right; j++ {
			res[k] = matrix[up][j]
			k++
		}

		up += 1
		if up > down {
			break
		}

		for i := up; i <= down; i++ {
			res[k] = matrix[i][right]
			k++
		}

		right -= 1
		if left > right {
			break
		}

		for j := right; j >= left; j-- {
			res[k] = matrix[down][j]
			k++
		}

		down -= 1
		if up > down {
			break
		}

		for i := down; i >= up; i-- {
			res[k] = matrix[i][left]
			k++
		}

		left += 1
		if left > right {
			break
		}
	}

	return res
}
