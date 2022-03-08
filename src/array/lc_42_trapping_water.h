#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief 接雨水
 *
 * @details
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * @par 示例
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 * @see [leetcode-42](https://leetcode.cn/problems/trapping-rain-water/)
 * https://leetcode.cn/problems/trapping-rain-water/solutions/9112/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
 */

namespace algo {
namespace array {
class TrapWater {
 public:
  int trap1(std::vector<int>& height) {
    int res = 0;

    int max_pos = std::max_element(height.begin(), height.end()) - height.begin();
    int max = height.at(max_pos);
    for (int k = 1; k <= max; k++) {
      bool is_started = false;
      int tmp = 0;
      for (int i = 0; i < height.size(); i++) {
        if (is_started && height[i] < k) {
          tmp++;
        }

        if (height[i] >= k) {
          res += tmp;
          tmp = 0;
          is_started = true;
        }
      }
    }

    return res;
  }

  int trap2(std::vector<int>& height) {
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
      if (i == 0 || i == height.size() - 1) {
        continue;
      }

      int left = height[i];
      for (int j = i - 1; j >= 0; j--) {
        if (height[j] > left) {
          left = height[j];
        }
      }

      int right = height[i];
      for (int j = i + 1; j < height.size(); j++) {
        if (height[j] > right) {
          right = height[j];
        }
      }

      int minh = std::min(left, right);
      if (height[i] < minh) {
        res += (minh - height[i]);
      }
    }

    return res;
  }

  int trap3(std::vector<int>& height) {
    int capacity = height.size();

    int dpl[capacity];
    dpl[0] = height[0];
    for (int i = 1; i < capacity; i++) {
      dpl[i] = std::max(height[i], dpl[i - 1]);
    }

    int dpr[capacity];
    dpr[capacity - 1] = height[capacity - 1];
    for (int i = capacity - 2; i >= 0; i--) {
      dpr[i] = std::max(height[i], dpr[i + 1]);
    }

    int res = 0;
    for (int i = 0; i < capacity; i++) {
      int minh = std::min(dpl[i], dpr[i]);
      if (height[i] < minh) {
        res += (minh - height[i]);
      }
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo