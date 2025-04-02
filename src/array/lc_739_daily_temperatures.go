package array

/**
 * @brief 每日温度
 *
 * @details
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
 * 下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 *
 * @par 示例
 *
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 *
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 *
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 *
 * @see [leetcode-739](https://leetcode.cn/problems/daily-temperatures/)
 */

func dailyTemperatures(temperatures []int) []int {
	var res []int = make([]int, len(temperatures))
	var stack []int

	for i := 0; i < len(temperatures); i++ {
		for len(stack) != 0 && temperatures[i] > temperatures[stack[len(stack)-1]] {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			res[top] = i - top
		}

		stack = append(stack, i)
	}

	return res
}
