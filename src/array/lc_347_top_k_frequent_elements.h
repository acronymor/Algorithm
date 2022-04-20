#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

/**
 * @namespace array
 * @brief 前 K 个高频元素
 */

namespace algo {
namespace array {
/**
 * @brief 前 K 个高频元素
 *
 * @details
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 *
 * @par 示例
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 * @see [leetcode-347](https://leetcode.cn/problems/top-k-frequent-elements/)
 */

class TopKFrequent {
 public:
  /**
   * @ingroup heap-priority-queue
   */
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> maps;
    for (auto num : nums) {
      maps[num]++;
    }

    // auto cmp = [](std::pair<int, int> left, std::pair<int, int> right) { return left.second > right.second; };
    // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> queues;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Cmp> queues;

    for (auto entry : maps) {
      queues.push(entry);
      if (queues.size() > k) {
        queues.pop();
      }
    }

    std::vector<int> res(k, 0);
    while (!queues.empty()) {
      res[k - 1] = queues.top().first;
      k--;
      queues.pop();
    }

    return res;
  }

 private:
  struct Cmp {
    bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right) {
      return left.second > right.second;
    }
  };
};
}  // namespace array
}  // namespace algo