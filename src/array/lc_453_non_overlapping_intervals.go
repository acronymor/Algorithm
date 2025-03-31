package array

import "sort"

/**
 * @brief 无重叠区间
 *
 * @details
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
 * 注意 只在一点上接触的区间是 不重叠的。例如 [1, 2] 和 [2, 3] 是不重叠的。
 *
 * @par 示例
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 *
 * 输入: intervals = [[1,2], [1,2], [1,2]]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 *
 * 输入: intervals = [[1,2], [2,3]]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 *
 * @see [leetcode-435](https://leetcode.cn/problems/non-overlapping-intervals/)
 */

func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var res int = 1
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] < intervals[i-1][1] {
			intervals[i][1] = min(intervals[i-1][1], intervals[i][1])
		} else {
			res++
		}
	}

	return len(intervals) - res
}
