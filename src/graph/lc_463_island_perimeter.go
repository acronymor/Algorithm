package graph

/**
 * @brief 岛屿的周长
 *
 * @details
 * 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
 * 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
 *
 * @par 示例
 * 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * 输出：16
 * 解释：它的周长是上面图片中的 16 个黄色的边
 *
 * 输入：grid = [[1]]
 * 输出：4
 *
 * 输入：grid = [[1,0]]
 * 输出：4
 *
 * @see [leetcode-463](https://leetcode.cn/problems/island-perimeter/)
 */

func islandPerimeter1(grid [][]int) int {
	var directions [][]int = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	var visited [][]bool = make([][]bool, len(grid))
	for i := range visited {
		visited[i] = make([]bool, len(grid[i]))
	}

	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[i]) {
			return 1
		}

		if grid[i][j] == 0 {
			return 1
		}

		if visited[i][j] {
			return 0
		}

		visited[i][j] = true

		var res int = 0
		for _, dir := range directions {
			x := i + dir[0]
			y := j + dir[1]
			res += dfs(x, y)
		}

		return res
	}

	var res int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if !visited[i][j] && grid[i][j] == 1 {
				res += dfs(i, j)
			}
		}
	}

	return res
}

func islandPerimeter2(grid [][]int) int {
	var directions [][]int = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

	var cnt int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == 0 {
				continue
			}

			if grid[i][j] == 1 {
				if i == 0 {
					cnt++
				}
				if i == len(grid)-1 {
					cnt++
				}
				if j == 0 {
					cnt++
				}
				if j == len(grid[i])-1 {
					cnt++
				}
			}

			for _, dir := range directions {
				x := i + dir[0]
				y := j + dir[1]

				if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[x]) {
					continue
				}

				if grid[x][y] == 0 {
					cnt++
				}
			}
		}
	}

	return cnt
}
