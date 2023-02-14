#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 最长重复子数组
 */

namespace algo {
namespace array {

/**
 * @brief 最长重复子数组
 *
 * @details
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 *
 * @par 示例
 *
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 *
 * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * 输出：5
 *
 * @see [leetcode-718](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/)
 */

class FindLength {
 public:
  /**
   * @ingroup dynamic-programming
   */
  int solve1(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) {
      return 0;
    }

    std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size(), 0));
    int res = 0;

    for (int i = 0; i < nums1.size(); i++) {
      if (nums1[i] == nums2[0]) {
        dp[i][0] = 1;
      }
      if (dp[i][0] > res) {
        res = dp[i][0];
      }
    }

    for (int i = 0; i < nums2.size(); i++) {
      if (nums1[0] == nums2[i]) {
        dp[0][i] = 1;
      }
      if (dp[0][i] > res) {
        res = dp[0][i];
      }
    }

    for (int i = 1; i < nums1.size(); i++) {
      for (int j = 1; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }

        if (dp[i][j] > res) {
          res = dp[i][j];
        }
      }
    }

    return res;
  }

  /**
   * @ingroup dynamic-programming
   */
  int solve2(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));
    int res = 0;

    for (int i = 1; i <= nums1.size(); i++) {
      for (int j = 1; j <= nums2.size(); j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }

        if (dp[i][j] > res) {
          res = dp[i][j];
        }
      }
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo