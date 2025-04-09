package graph

/**
 * @brief 冗余连接
 *
 * @details
 * 树可以看成是一个连通且 无环 的 无向 图。
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。
 * 图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
 *
 * @par 示例
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 * @see [leetcode-684](https://leetcode.cn/problems/redundant-connection/)
 */

func findRedundantConnection(edges [][]int) []int {
	var parent []int = make([]int, len(edges)+1)
	for i := 0; i < len(edges); i++ {
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

		if from == to {
			return edge
		}
		parent[from] = to
	}

	return []int{}
}
