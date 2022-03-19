#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 两数之和
 */

namespace algo {
namespace array {
/**
 * @brief 两数之和
 *
 * @details
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个
 * 整数，并返回它们的数组下标。 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 *
 * @par 示例
 *
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 *
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 *
 * @see [leetcode-1](https://leetcode.cn/problems/two-sum/)
 */

class TwoSum {
 public:
  /**
   *  @ingroup hash-table
   */
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash_table;

    for (int i = 0; i < nums.size(); i++) {
      // if (hash_table.contains(tmp)) {
      auto itr = hash_table.find(target - nums[i]);
      if (itr != hash_table.end()) {
        return {itr->second, i};
      }
      hash_table.emplace(nums[i], i);
    }

    return {};
  }
};
}  // namespace array
}  // namespace algo