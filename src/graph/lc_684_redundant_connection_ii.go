package graph

/**
 * @brief 冗余连接 II
 *
 * @details
 * 在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 *
 * @par 示例
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 *
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 *
 * @see [leetcode-685](https://leetcode.cn/problems/redundant-connection-ii/)
 */

func findRedundantDirectedConnection(edges [][]int) []int {
	var parent []int = make([]int, len(edges)+1)

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

	var inDegrees []int = make([]int, len(edges)+1)
	for _, edge := range edges {
		inDegrees[edge[1]]++
	}
	var dup []int

	for i, edge := range edges {
		if inDegrees[edge[1]] == 2 {
			dup = append(dup, i)
		}
	}

	if len(dup) > 0 {
		for i, edge := range edges {
			if i == dup[1] {
				continue
			}

			from := find(edge[0])
			to := find(edge[1])

			if from == to {
				return edges[dup[0]]
			}
			parent[from] = to
		}
		return edges[dup[1]]
	}

	for _, edge := range edges {
		from := find(edge[0])
		to := find(edge[1])

		if from == to {
			return edge
		}
		parent[from] = to
	}

	return []int{}
}
