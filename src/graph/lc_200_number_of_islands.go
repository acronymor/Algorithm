package graph

import "container/list"

/**
 * @brief 岛屿数量
 *
 * @details
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 * @par 示例
 *
 * 输入：grid = [
 *  ["1","1","1","1","0"],
 *  ["1","1","0","1","0"],
 *  ["1","1","0","0","0"],
 *  ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 * 输入：grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 * @see [leetcode-200](https://leetcode.cn/problems/number-of-islands/)
 */

func numIslands1(grid [][]byte) int {
	var visited [][]bool = make([][]bool, len(grid))
	for i, _ := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var directions [][]int = [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	var dfs func(i, j int)

	dfs = func(i, j int) {
		if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[i]) {
			return
		}

		if visited[i][j] || grid[i][j] == '0' {
			return
		}

		visited[i][j] = true

		for _, dir := range directions {
			x := i + dir[0]
			y := j + dir[1]

			dfs(x, y)
		}
	}

	var res int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if !visited[i][j] && grid[i][j] == '1' {
				dfs(i, j)
				res++
			}
		}
	}

	return res
}

func numIslands2(grid [][]byte) int {
	var visited [][]bool = make([][]bool, len(grid))
	for i, _ := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var directions [][]int = [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	var dfs func(i, j int)

	dfs = func(i, j int) {
		visited[i][j] = true
		for _, dir := range directions {
			x := i + dir[0]
			y := j + dir[1]

			if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[x]) {
				continue
			}

			if visited[x][y] || grid[x][y] == '0' {
				continue
			}

			dfs(x, y)
		}
	}

	var res int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if !visited[i][j] && grid[i][j] == '1' {
				dfs(i, j)
				res++
			}
		}
	}

	return res
}

func numIslands3(grid [][]byte) int {
	var visited [][]bool = make([][]bool, len(grid))
	for i, _ := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var directions [][]int = [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	var bfs func(i, j int)
	bfs = func(i, j int) {
		visited[i][j] = true
		queue := list.New()
		queue.PushBack([]int{i, j})

		for queue.Len() > 0 {
			front := queue.Front()
			cur := front.Value.([]int)
			queue.Remove(front)

			for _, dir := range directions {
				x := cur[0] + dir[0]
				y := cur[1] + dir[1]

				if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[i]) {
					continue
				}

				if visited[x][y] || grid[x][y] == '0' {
					continue
				}

				queue.PushBack([]int{x, y})
				visited[x][y] = true
			}
		}
	}

	var res int = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if !visited[i][j] && grid[i][j] == '1' {
				bfs(i, j)
				res++
			}
		}
	}

	return res
}
