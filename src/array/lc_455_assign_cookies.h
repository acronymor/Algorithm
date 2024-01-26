#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @namespace array
 * @brief 分发饼干
 */
namespace algo {
namespace array {
/**
 * @brief 分发饼干
 *
 * @details
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
 * 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果
 * s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i
 * ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 *
 * @par 示例
 *
 * 输入: g = [1,2,3], s = [1,1]
 * 输出: 1
 *
 * 输入: g = [1,2], s = [1,2,3]
 * 输出: 2
 *
 * @see [leetcode-455](https://leetcode.cn/problems/assign-cookies/)
 */

class AssignCookies {
 public:
  /**
   * @ingroup greedy
   */
  int solve(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int res = 0;

    for (int i = g.size() - 1, j = s.size() - 1; i >= 0; i--) {
      if (j >= 0 && s[j] >= g[i]) {
        res++;
        j--;
      }
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo