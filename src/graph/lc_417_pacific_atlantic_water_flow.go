package graph

/**
 * @brief 太平洋大西洋水流问题
 *
 * @details
 * 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
 * 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。
 * 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
 * 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。
 *
 * @par 示例
 * 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *
 * 示例 2：
 *输入: heights = [[2,1],[1,2]]
 *输出: [[0,0],[0,1],[1,0],[1,1]]
 *
 * @see [leetcode-417](https://leetcode.cn/problems/pacific-atlantic-water-flow/)
 */

func pacificAtlantic(heights [][]int) [][]int {
	var directions [][]int = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

	var dfs func(visited [][]bool, i, j int)

	dfs = func(visited [][]bool, i, j int) {
		visited[i][j] = true

		for _, dir := range directions {
			x := i + dir[0]
			y := j + dir[1]

			if i < 0 || i >= len(heights) || j < 0 || j >= len(heights[i]) {
				continue
			}

			if x < 0 || x >= len(heights) || y < 0 || y >= len(heights[i]) {
				continue
			}

			if heights[i][j] > heights[x][y] || visited[x][y] {
				continue
			}

			dfs(visited, x, y)
		}
	}

	var ltVisited [][]bool = make([][]bool, len(heights))
	for i, _ := range heights {
		ltVisited[i] = make([]bool, len(heights[i]))
	}

	var rbVisited [][]bool = make([][]bool, len(heights))
	for i, _ := range heights {
		rbVisited[i] = make([]bool, len(heights[i]))
	}

	for i := 0; i < len(heights); i++ {
		dfs(ltVisited, i, 0)
		dfs(rbVisited, i, len(heights[0])-1)
	}

	for j := 0; j < len(heights[0]); j++ {
		dfs(ltVisited, 0, j)
		dfs(rbVisited, len(heights)-1, j)
	}

	var res [][]int
	for i := 0; i < len(heights); i++ {
		for j := 0; j < len(heights[i]); j++ {
			if ltVisited[i][j] && rbVisited[i][j] {
				res = append(res, []int{i, j})
			}
		}
	}

	return res
}
