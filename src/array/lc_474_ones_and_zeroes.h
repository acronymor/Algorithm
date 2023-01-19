#include <iostream>
#include <numeric>
#include <vector>

/**
 * @namespace array
 * @brief 一和零
 */

namespace algo {
namespace array {

/**
 * @brief 一和零
 *
 * @details
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 *
 * @par 示例
 *
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3
 * 。
 *
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 *
 * @see [leetcode-474](https://leetcode.cn/problems/ones-and-zeroes/)
 */

class FindMaxForm {
 public:
  /**
   *  @ingroup dynamic-programming
   */
  int solve(std::vector<std::string>& strs, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (const std::string& str : strs) {
      int oneNum = 0, zeroNum = 0;
      for (char c : str) {
        c == '0' ? zeroNum++ : oneNum++;
      }
      for (int i = m; i >= zeroNum; i--) {
        for (int j = n; j >= oneNum; j--) {
          dp[i][j] = std::max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
}  // namespace array
}  // namespace algo