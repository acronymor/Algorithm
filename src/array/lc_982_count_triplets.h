#include <iostream>
#include <vector>

/**
 * @namespace array
 * @brief 按位与为零的三元组
 */

namespace algo {
namespace array {

/**
 * @brief 按位与为零的三元组
 *
 * @details
 * 给你一个整数数组 nums ，返回其中 按位与三元组 的数目。
 * 按位与三元组 是由下标 (i, j, k) 组成的三元组，并满足下述全部条件：
 * 0 <= i < nums.length
 * 0 <= j < nums.length
 * 0 <= k < nums.length
 * nums[i] & nums[j] & nums[k] == 0 ，其中 & 表示按位与运算符。
 *
 * @par 示例
 *
 * 输入：nums = [2,1,3]
 * 输出：12
 *
 * 输入：nums = [0,0,0]
 * 输出：27
 *
 * @see [leetcode-982](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/)
 */

class CountTriplets {
 public:
  /**
   * @ingroup backtracking
   */
  int solve1(const std::vector<int>& nums) {
    int allCnt = 0;
    int cnt = 0;
    int res = 0xFFFF;
    backtracking(nums, &allCnt, &cnt, &res);
    return allCnt;
  }

  /**
   * @ingroup backtracking
   */
  int solve2(const std::vector<int>& nums) {
    std::vector<int> hash(1 << 16, 0);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        hash[nums[i] & nums[j]]++;
      }
    }

    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < hash.size(); j++) {
        if ((nums[i] & j) == 0) {
          res += hash[j];
        }
      }
    }
    return res;
  }

 private:
  // overtime
  void backtracking(const std::vector<int>& nums, int* allCnt, int* cnt, int* res) {
    if ((*cnt) == 3) {
      if (*res == 0) {
        (*allCnt)++;
      }

      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      int tmp = (*res);
      (*cnt)++;
      (*res) = (*res) & nums[i];
      backtracking(nums, allCnt, cnt, res);
      (*res) = tmp;
      (*cnt)--;
    }
  }
};
}  // namespace array
}  // namespace algo