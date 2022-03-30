#include <iostream>
#include <string>
#include <unordered_set>

/**
 * @namespace string
 * @brief 无重复字符的最长子串
 */

namespace algo {
namespace string {

/**
 * @brief 无重复字符的最长子串
 *
 * @details
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * @par 示例
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 * @see [leetcode-3](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)
 */

class LengthOfLongestSubstring {
 public:
  /**
   * @ingroup sliding-window
   */
  int lengthOfLongestSubstring(std::string s) {
    size_t res = 0;
    std::unordered_set<char> sets;
    for (size_t i = 0, j = 0; j < s.length(); j++) {
      // while (sets.contains(s[j])) {
      while (sets.count(s[j]) > 0) {
        sets.erase(s[i]);
        i++;
      }
      res = std::max(res, j - i + 1);
      sets.insert(s[j]);
    }

    return res;
  }
};
}  // namespace string
};  // namespace algo