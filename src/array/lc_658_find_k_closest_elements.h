#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @namespace array
 * @brief 找到 K 个最接近的元素
 */
namespace algo {
namespace array {
/**
 * @brief 找到 K 个最接近的元素
 *
 * @details
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。
 * 返回的结果必须要是按升序排好的。 整数 a 比整数 b 更接近 x 需要满足： |a - x| < |b - x| 或者 |a - x| == |b - x|
 * 且 a < b
 *
 * @par 示例
 *
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 *
 * 输入：arr = [1,2,3,4,5], k = 4, x = -1
 * 输出：[1,2,3,4]
 *
 * @see
 * [leetcode-658](https://leetcode.cn/problems/find-k-closest-elements/)
 */

class FindClosestElements {
 public:
  std::vector<int> solve1(std::vector<int>& arr, int k, int x) {
    std::sort(arr.begin(), arr.end(), [x](int a, int b) -> bool {
      return std::abs(a - x) < std::abs(b - x) || std::abs(a - x) == std::abs(b - x) && a < b;
    });
    std::sort(arr.begin(), arr.begin() + k);
    return std::vector<int>(arr.begin(), arr.begin() + k);
  }

  /**
   * @ingroup binary-search
   */
  std::vector<int> solve2(std::vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size();

    while (left < right) {
      int mid = (left + right) / 2;
      if (x - arr[mid] > arr[mid + k] - x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    std::vector<int> res;
    for (int i = left; i < left + k; i++) {
      res.push_back(arr[i]);
    }

    return res;
  }

  std::vector<int> solve3(std::vector<int>& arr, int k, int x) {
    int right = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left = right - 1;
    while (k-- != 0) {
      if (left < 0) {
        right++;
      } else if (right >= arr.size()) {
        left--;
      } else if (x - arr[left] <= arr[right] - x) {
        left--;
      } else {
        right++;
      }
    }

    return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);
  }
};
}  // namespace array
}  // namespace algo