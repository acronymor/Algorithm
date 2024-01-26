#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

/**
 * @namespace array
 * @brief 两个数组的交集
 */

namespace algo {
namespace array {

/**
 * @brief 两个数组的交集
 *
 * @details
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 * @par 示例
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 * @see [leetcode-349](https://leetcode.cn/problems/intersection-of-two-arrays)
 */

class Intersection {
 public:
  /**
   * @ingroup hash-table
   */
  std::vector<int> intersection1(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> sets1;
    for (auto num : nums1) {
      sets1.insert(num);
    }

    std::unordered_set<int> sets2;
    for (auto num : nums2) {
      sets2.insert(num);
    }

    std::vector<int> res;
    for (auto num : sets1) {
      // if(sets2.contains(num)) {
      if (sets2.count(num) > 0) {
        res.push_back(num);
      }
    }

    return res;
  };

  std::vector<int> intersection2(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    std::vector<int> res;
    res.reserve(std::min(nums1.size(), nums2.size()));
    std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(res));

    std::unordered_set<int> sets;
    sets.insert(res.begin(), res.end());

    return {sets.begin(), sets.end()};
  };
};
}  // namespace array
}  // namespace algo