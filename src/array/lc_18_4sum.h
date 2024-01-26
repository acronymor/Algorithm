#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @namespace array
 * @brief 四数之和
 */

namespace algo {
namespace array {
/**
 * @brief 四数之和
 *
 * @details
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 0 <= a, b, c, d < n a、b、c 和 d
 * 互不相同 nums[a] + nums[b] + nums[c] + nums[d] == target 你可以按 任意顺序 返回答案 。
 *
 * @par 示例
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 * @see [leetcode-18](https://leetcode.cn/problems/4sum/)
 */

class FourSum {
 public:
  /**
   * @ingroup two-pointers
   */
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 0 && nums[i] > target) {
        return res;
      }

      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }

      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
          break;
        }

        if (j > i + 1 && nums[j - 1] == nums[j]) {
          continue;
        }

        int left = j + 1;
        int right = nums.size() - 1;
        while (right > left) {
          long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum < target) {
            left++;
          } else if (sum > target) {
            right--;
          } else {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});

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
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo