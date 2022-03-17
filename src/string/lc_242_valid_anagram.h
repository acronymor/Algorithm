#include <iostream>
#include <string>

/**
 * @namespace string
 * @brief 有效的字母异位词
 */

namespace algo {
namespace string {

/**
 * @brief 有效的字母异位词
 *
 * @details
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 *
 * @par 示例
 *
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 *
 * 输入: s = "rat", t = "car"
 * 输出: false
 *
 * @see [leetcode-242](https://leetcode.cn/problems/valid-anagram/)
 */

class IsAnagram {
 public:
  /**
   * @ingroup hash-table
   */
  bool isAnagram(const std::string& s, const std::string& t) {
    uint32_t map1[26] = {0};
    for (const auto& ch : s) {
      map1[ch - 'a']++;
    }

    uint32_t map2[26] = {0};
    for (const auto& ch : t) {
      map2[ch - 'a']++;
    }

    for (size_t i = 0; i < 26; i++) {
      if (map1[i] != map2[i]) {
        return false;
      }
    }

    return true;
  }
};
}  // namespace string
}  // namespace algo