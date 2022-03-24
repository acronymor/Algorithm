#include <iostream>
#include <string>

/**
 * @namespace string
 * @brief 赎金信
 */

namespace algo {
namespace string {

/**
 * @brief 赎金信
 *
 * @details
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 如果可以，返回 true ；否则返回 false 。
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 * @par 示例
 *
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 * @see [leetcode-383](https://leetcode.cn/problems/ransom-note/)
 */

class CanConstruct {
 public:
  /**
   * @ingroup hash-table
   */
  bool canConstruct(std::string ransomNote, std::string magazine) {
    int hash_table[26] = {0};
    for (auto& ch : magazine) {
      hash_table[ch - 'a']++;
    }

    for (auto& ch : ransomNote) {
      int at = --hash_table[ch - 'a'];
      if (at < 0) {
        return false;
      }
    }

    return true;
  }
};
}  // namespace string
}  // namespace algo