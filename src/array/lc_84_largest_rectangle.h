#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

namespace algo {
namespace array {

/**
 * @brief 柱状图中最大的矩形
 *
 * @details
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 * @par 示例
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 * @see [leetcode-84](https://leetcode.cn/problems/largest-rectangle-in-histogram/)
 */

class LargestRectangleArea {
 public:
  /**
   * @ingroup two-pointers
   */
  int largestRectangleArea1(std::vector<int>& heights) {
    int res = 0;

    for (int i = 0; i < heights.size(); i++) {
      int left = i;
      for (int j = i - 1; j >= 0; j--) {
        if (heights[j] < heights[i]) {
          break;
        }
        left = j;
      }

      int right = i;
      for (int j = i + 1; j < heights.size(); j++) {
        if (heights[j] < heights[i]) {
          break;
        }
        right = j;
      }

      res = std::max(res, (right - left + 1) * heights[i]);
    }
    return res;
  }

  /**
   * @ingroup dynamic-programming
   */
  int largestRectangleArea2(std::vector<int>& heights) {
    int capacity = heights.size();

    int dpl[capacity];
    dpl[0] = -1;
    for (int i = 1; i < heights.size(); i++) {
      int j = i - 1;
      while (j >= 0 && heights[i] <= heights[j]) {
        j = dpl[j];
      }
      dpl[i] = j;
    }

    int dpr[capacity];
    dpr[capacity - 1] = capacity;
    for (int i = capacity - 2; i >= 0; i--) {
      int j = i + 1;
      while (j < capacity && heights[i] <= heights[j]) {
        j = dpr[j];
      }
      dpr[i] = j;
    }

    int res = 0;
    for (int i = 0; i < capacity; i++) {
      res = std::max(res, (dpr[i] - dpl[i] - 1) * heights[i]);
    }

    return res;
  }

  /**
   * @ingroup monotonic-stack
   */
  int largestRectangleArea3(std::vector<int>& heights) {
    int res = 0;
    std::stack<size_t> stacks;

    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    for (size_t i = 0; i < heights.size(); i++) {
      while (!stacks.empty() && heights[i] < heights[stacks.top()]) {
        size_t mid = stacks.top();
        stacks.pop();

        int area = (i - stacks.top() - 1) * heights[mid];
        res = std::max(res, area);
      }
      stacks.push(i);
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo