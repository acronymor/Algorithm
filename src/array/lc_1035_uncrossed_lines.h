#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 不相交的线
 */

namespace algo {
namespace array {

/**
 * @brief 不相交的线
 *
 * @details
 * 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
 * 现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
 *  nums1[i] == nums2[j]
 * 且绘制的直线不与任何其他连线（非水平线）相交。
 * 请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。 以这种方法绘制线条，并返回可以绘制的最大连线数。
 *
 * @par 示例
 *
 * 输入：nums1 = [1,4,2], nums2 = [1,2,4]
 * 输出：2
 * 解释：可以画出两条不交叉的线，如上图所示。
 * 但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
 *
 * 输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
 * 输出：3
 *
 * @see [leetcode-1035](https://leetcode.cn/problems/uncrossed-lines/)
 */

class MaxUncrossedLines {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

    for (int i = 1; i <= nums1.size(); i++) {
      for (int j = 1; j <= nums2.size(); j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[nums1.size()][nums2.size()];
  }
};
}  // namespace array
}  // namespace algo