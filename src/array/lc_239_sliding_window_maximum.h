#include <deque>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

/**
 * @namespace array
 * @brief 滑动窗口最大值
 */

namespace algo {
namespace array {
namespace {
class Queue {
 public:
  void pop(int value) {
    if (!queues.empty() && value == queues.front()) {
      queues.pop_front();
    }
  }

  void push(int value) {
    while (!queues.empty() && value > queues.back()) {
      queues.pop_back();
    }
    queues.push_back(value);
  }

  int front() { return queues.front(); }

 private:
  std::deque<int> queues;
};
}  // namespace

/**
 * @brief 滑动窗口最大值
 *
 * @details
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值 。
 *
 * @par 示例
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * @code
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 *  @endcode
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 * @see [leetcode-239](https://leetcode.cn/problems/sliding-window-maximum/)
 */

class MaxSlidingWindow {
 public:
  // overtime
  std::vector<int> maxSlidingWindow1(std::vector<int>& nums, int k) {
    std::vector<int> res;
    for (size_t i = 0, j = i + k; j <= nums.size(); i++, j++) {
      auto itr = std::max_element(nums.begin() + i, nums.begin() + j);
      res.push_back(*itr);
    }

    return res;
  }

  /**
   * @ingroup monotonic-queue
   */
  std::vector<int> maxSlidingWindow2(std::vector<int>& nums, int k) {
    Queue queues;
    for (int i = 0; i < k; i++) {
      queues.push(nums[i]);
    }

    std::vector<int> res;
    res.push_back(queues.front());

    for (int i = k; i < nums.size(); i++) {
      queues.pop(nums[i - k]);
      queues.push(nums[i]);
      res.push_back(queues.front());
    }

    return res;
  }

  /**
   * @ingroup heap-priority-queue
   */
  std::vector<int> maxSlidingWindow3(std::vector<int>& nums, int k) {
    std::priority_queue<std::pair<int, int>> queues;
    for (int i = 0; i < k; i++) {
      queues.emplace(nums[i], i);
    }

    std::vector<int> res = {queues.top().first};

    for (int i = k; i < nums.size(); i++) {
      queues.emplace(nums[i], i);

      while (queues.top().second <= i - k) {
        queues.pop();
      }

      res.push_back(queues.top().first);
    }

    return res;
  }
};
}  // namespace array
}  // namespace algo