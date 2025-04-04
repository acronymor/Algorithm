package graph

import "container/list"

/**
 * @brief 岛屿的最大面积
 *
 * @details
 * 给你一个大小为 m x n 的二进制矩阵 grid 。
 * 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
 * 岛屿的面积是岛上值为 1 的单元格的数目。
 * 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 *
 * @par 示例
 *
 * 输入：grid = [
 *  ["1","1","1","1","0"],
 *  ["1","1","0","1","0"],
 *  ["1","1","0","0","0"],
 *  ["0","0","0","0","0"]
 * ]
 * 输出：9
 *
 * 输入：grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * 输出：4
 *
 * @see [leetcode-695](https://leetcode.cn/problems/max-area-of-island/)
 */

func maxAreaOfIsland1(grid [][]int) int {
	var visited [][]bool = make([][]bool, len(grid))
	for i, _ := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var directions [][]int = [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}

	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[i]) {
			return 0
		}

		if visited[i][j] || grid[i][j] == 0 {
			return 0
		}

		visited[i][j] = true
		var res = 1

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
				res = max(res, dfs(i, j))
			}
		}
	}

	return res
}

func maxAreaOfIsland2(grid [][]int) int {
	var visited [][]bool = make([][]bool, len(grid))
	for i, _ := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var directions [][]int = [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	var bfs func(i, j int) int

	bfs = func(i, j int) int {
		queue := list.New()
		queue.PushBack([]int{i, j})
		visited[i][j] = true

		var res = 1

		for queue.Len() > 0 {
			front := queue.Front()
			cur := front.Value.([]int)
			queue.Remove(front)

			for _, dir := range directions {
				x := cur[0] + dir[0]
				y := cur[1] + dir[1]

				if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[x]) {
					continue
				}

				if visited[x][y] || grid[x][y] == 0 {
					continue
				}

				queue.PushBack([]int{x, y})
				visited[x][y] = true
				res += grid[x][y]
			}
		}

		return res
	}

	var res int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if !visited[i][j] && grid[i][j] == 1 {
				res = max(res, bfs(i, j))
			}
		}
	}

	return res
}
