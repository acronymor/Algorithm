#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief 使字符串平衡的最少删除次数
 */

namespace algo {
namespace string {

/**
 * @brief 使字符串平衡的最少删除次数
 *
 * @details
 * 给你一个字符串 s ，它仅包含字符 'a' 和 'b'
 * 你可以删除 s 中任意数目的字符，使得 s 平衡 。当不存在下标对 (i,j) 满足 i < j ，且 s[i] = 'b' 的同时 s[j]= 'a'，
 * 此时认为 s 是 平衡 的。 请你返回使 s 平衡 的 最少 删除次数。
 *
 * @par 示例
 *
 * 输入：s = "aababbab"
 * 输出：2
 *
 * 输入：s = "bbaaaaabb"
 * 输出：2
 *
 * @see [leetcode-1653](https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/)
 */

class MinDistance {
 public:
  int solve1(const std::string& s) {
    int cnt = 0;
    for (char ch : s) {
      cnt += 'b' - ch;
    }

    int res = cnt;
    for (char ch : s) {
      ch == 'a' ? cnt-- : cnt++;
      res = std::min(res, cnt);
    }
    return res;
  }

  /**
   * @ingroup dynamic-programming
   */
  int solve2(const std::string& s) {
    int dp = 0, cnt = 0;
    for (char ch : s) {
      if (ch == 'b') {
        cnt++;
      } else {
        dp = std::min(dp + 1, cnt);
      }
    }

    return dp;
  }
};
}  // namespace string
}  // namespace algo