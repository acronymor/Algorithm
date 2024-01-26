#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

/**
 * @namespace array
 * @brief 三数之和
 */

namespace algo {
namespace array {
/**
 * @brief 三数之和
 *
 * @details
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足
 * nums[i] + nums[j] + nums[k] == 0 。请 你返回所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 *
 * @par 示例
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 * @see [leetcode-15](https://leetcode.cn/problems/3sum/)
 */

class ThreeSum {
 public:
  /**
   *  @ingroup hash-table
   */
  std::vector<std::vector<int>> threeSum1(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      std::unordered_set<int> sets;
      for (int j = i + 1; j < nums.size(); j++) {
        if (j > i + 2 && nums[j - 2] == nums[j - 1] && nums[j - 1] == nums[j]) {
          continue;
        }

        int target = 0 - (nums[i] + nums[j]);
        if (sets.find(target) != sets.end()) {
          res.push_back({target, nums[i], nums[j]});
          sets.erase(target);
        } else {
          sets.insert(nums[j]);
        }
      }
    }
    return res;
  }

  /**
   * @ingroup two-pointers
   */
  std::vector<std::vector<int>> threeSum2(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        return res;
      }

      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }

      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          res.push_back({nums[i], nums[left], nums[right]});

          while (right > left && nums[left] == nums[left + 1]) {
            left++;
          }

          while (right > left && nums[right - 1] == nums[right]) {
            right--;
          }

          left++;
          right--;
        }
      }
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo