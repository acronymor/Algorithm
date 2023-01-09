#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 无重叠区间
 */
namespace algo {
namespace array {
/**
 * @brief 无重叠区间
 *
 * @details
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠。
 *
 * @par 示例
 *
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 *
 * 输入: intervals = [ [1,2], [1,2], [1,2] ]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 *
 * 输入: intervals = [ [1,2], [2,3] ]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 *
 * @see [leetcode-435](https://leetcode.cn/problems/non-overlapping-intervals/)
 */

class EraseOverlapIntervals {
 public:
  /**
   * @ingroup greedy
   */
  int solve(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) -> bool { return a[1] < b[1]; });

    int cnt = 1;

    for (int i = 1, end = intervals[0][1]; i < intervals.size(); i++) {
      if (end <= intervals[i][0]) {
        end = intervals[i][1];
        cnt++;
      }
    }

    return intervals.size() - cnt;
  }
};
}  // namespace array
}  // namespace algo