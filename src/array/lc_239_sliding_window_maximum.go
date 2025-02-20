package array

import (
	"math"
)

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

func maxSlidingWindow1(nums []int, k int) []int {
	var res []int

	for j := k; j <= len(nums); j++ {
		var maxNum int = math.MinInt
		for i := j - k; i < j; i++ {
			maxNum = int(math.Max(float64(maxNum), float64(nums[i])))
		}
		res = append(res, maxNum)
	}

	return res
}

type MonotonicQueue []int

func (s *MonotonicQueue) front() int {
	return (*s)[0]
}

func (s *MonotonicQueue) back() int {
	return (*s)[len(*s)-1]
}

func (s *MonotonicQueue) empty() bool {
	return len(*s) == 0
}

func (s *MonotonicQueue) push(x int) {
	for !s.empty() && s.back() < x {
		*s = (*s)[:len(*s)-1]
	}
	*s = append(*s, x)
}

func (s *MonotonicQueue) pop(x int) {
	if !s.empty() && s.front() == x {
		*s = (*s)[1:]
	}
}

func maxSlidingWindow2(nums []int, k int) []int {
	var queue MonotonicQueue = MonotonicQueue{}
	var res []int

	for i := 0; i < k; i++ {
		queue.push(nums[i])
	}
	res = append(res, queue.front())

	for i := k; i < len(nums); i++ {
		queue.pop(nums[i-k])
		queue.push(nums[i])
		res = append(res, queue.front())
	}

	return res
}
