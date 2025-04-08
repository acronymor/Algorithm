package graph

import "container/list"

/**
 * @brief 寻找图中是否存在路径
 *
 * @details
 * 有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。
 * 图中的边用一个二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。
 * 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。
 * 请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
 * 给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。
 *
 * @par 示例
 * 输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * 输出：true
 *
 * 输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
 * 输出：false
 *
 * @see [leetcode-1971](https://leetcode.cn/problems/find-if-path-exists-in-graph/)
 */

func validPath1(n int, edges [][]int, source int, destination int) bool {
	var graph map[int][]int = make(map[int][]int, n)
	for _, edge := range edges {
		from := edge[0]
		to := edge[1]
		graph[from] = append(graph[from], to)
		graph[to] = append(graph[to], from)
	}

	var visited []bool = make([]bool, n)

	var dfs func(from, to int) bool
	dfs = func(from, to int) bool {
		if from == to {
			return true
		}

		visited[from] = true

		for _, next := range graph[from] {
			if !visited[next] && dfs(next, to) {
				return true
			}
		}

		return false
	}

	return dfs(source, destination)
}

func validPath2(n int, edges [][]int, source int, destination int) bool {
	var graph map[int][]int = make(map[int][]int, n)
	for _, edge := range edges {
		from := edge[0]
		to := edge[1]
		graph[from] = append(graph[from], to)
		graph[to] = append(graph[to], from)
	}

	var visited []bool = make([]bool, n)
	var queue = list.New()
	queue.PushBack(source)
	visited[source] = true

	for queue.Len() != 0 {
		from := queue.Front()
		queue.Remove(from)
		node := from.Value.(int)

		if node == destination {
			break
		}

		for _, next := range graph[node] {
			if !visited[next] {
				queue.PushBack(next)
				visited[next] = true
			}
		}
	}

	return visited[destination]
}

func validPath3(n int, edges [][]int, source int, destination int) bool {
	var parent []int = make([]int, n)
	for i := range parent {
		parent[i] = i
	}

	var find func(x int) int
	find = func(x int) int {
		if parent[x] == x {
			return x
		}

		parent[x] = find(parent[x])
		return parent[x]
	}

	for _, edge := range edges {
		from := find(edge[0])
		to := find(edge[1])
		parent[from] = to
	}

	return find(source) == find(destination)
}
