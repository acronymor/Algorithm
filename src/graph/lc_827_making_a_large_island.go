package graph

/**
 * @brief 最大人工岛
 *
 * @details
 * 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
 * 返回执行此操作后，grid 中最大的岛屿面积是多少？
 * 岛屿 由一组上、下、左、右四个方向相连的 1 形成。
 *
 * @par 示例
 * 输入: grid = [[1, 0], [0, 1]]
 * 输出: 3
 * 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
 *
 * 输入: grid = [[1, 1], [1, 0]]
 * 输出: 4
 * 解释: 将一格0变成1，岛屿的面积扩大为 4。
 *
 * 输入: grid = [[1, 1], [1, 1]]
 * 输出: 4
 * 解释: 没有0可以让我们变成1，面积依然为 4。
 *
 * @see [leetcode-827](https://leetcode.cn/problems/making-a-large-island/)
 */

func largestIsland(grid [][]int) int {
	var direction [][]int = [][]int{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}

	var visited [][]bool = make([][]bool, len(grid))
	for i, _ := range grid {
		visited[i] = make([]bool, len(grid[i]))
	}

	var dfs func(i, j, mark int) int

	dfs = func(i, j, mark int) int {
		visited[i][j] = true
		grid[i][j] = mark

		var res int = 1
		for _, dir := range direction {
			x := i + dir[0]
			y := j + dir[1]

			if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[x]) {
				continue
			}

			if grid[x][y] == 0 || visited[x][y] {
				continue
			}

			res += dfs(x, y, mark)
		}
		return res
	}

	var isAllLand bool = true
	var table map[int]int = make(map[int]int)
	var mark int = 2
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == 0 {
				isAllLand = false
			}

			if grid[i][j] == 1 && !visited[i][j] {
				table[mark] = dfs(i, j, mark)
				mark++
			}
		}
	}

	var res int = 0
	if isAllLand {
		// 全部是陆地
		res = len(grid) * len(grid[0])
		return res
	}

	var newVisited map[int]bool = make(map[int]bool, mark)
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] != 0 {
				continue
			}

			count := 1
			newVisited = make(map[int]bool, mark)

			for _, dir := range direction {
				x := i + dir[0]
				y := j + dir[1]
				if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[x]) {
					continue
				}

				id := grid[x][y]

				if _, ok := newVisited[id]; ok {
					continue
				}

				count += table[id]
				newVisited[id] = true
			}

			res = max(res, count)
		}
	}

	return res
}
