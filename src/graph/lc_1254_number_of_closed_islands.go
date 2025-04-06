package graph

/**
 * @brief 统计封闭岛屿的数目
 *
 * @details
 * 二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。
 * 请返回 封闭岛屿 的数目。
 *
 * @par 示例
 * 输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * 输出：2
 * 解释：
 * 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
 *
 * 输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * 输出：1
 *
 * @see [leetcode-1254](https://leetcode.cn/problems/number-of-closed-islands/)
 */

func closedIsland(grid [][]int) int {
	var visited [][]bool = make([][]bool, len(grid))
	for i := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var directions [][]int = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	var dfs func(i, j int)

	dfs = func(i, j int) {
		visited[i][j] = true

		for _, dir := range directions {
			x := i + dir[0]
			y := j + dir[1]

			if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[x]) {
				continue
			}

			if visited[x][y] || grid[x][y] == 1 {
				continue
			}

			dfs(x, y)
		}
	}

	for i := 0; i < len(grid); i++ {
		if grid[i][0] == 0 {
			dfs(i, 0)
		}

		if grid[i][len(grid[i])-1] == 0 {
			dfs(i, len(grid[i])-1)
		}
	}

	for j := 0; j < len(grid[0]); j++ {
		if grid[0][j] == 0 {
			dfs(0, j)
		}

		if grid[len(grid)-1][j] == 0 {
			dfs(len(grid)-1, j)
		}
	}

	var res int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if !visited[i][j] && grid[i][j] == 0 {
				dfs(i, j)
				res++
			}
		}
	}

	return res
}
