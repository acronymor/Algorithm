package array

import "math"

/**
 * @brief 加油站
 *
 * @details
 * 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 * 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
 *
 * @par 示例
 *
 * 输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * 输出: 3
 *
 * 输入: gas = [2,3,4], cost = [3,4,3]
 * 输出: -1
 *
 * @see [leetcode-134](https://leetcode.cn/problems/gas-station/)
 */

func canCompleteCircuit1(gas []int, cost []int) int {
	curSum, totalSum := 0, 0
	var start int = 0
	for i := 0; i < len(gas) && i < len(cost); i++ {
		tmp := gas[i] - cost[i]
		curSum += tmp
		totalSum += tmp

		if curSum < 0 {
			start = i + 1
			curSum = 0
		}
	}

	if totalSum < 0 {
		return -1
	}

	return start
}

func canCompleteCircuit2(gas []int, cost []int) int {
	var start int = 0
	var spare int = 0
	var minSpare int = math.MaxInt32
	for i := 0; i < len(gas) && i < len(cost); i++ {
		spare += gas[i] - cost[i]
		if spare < minSpare {
			minSpare = spare
			start = i
		}
	}

	if spare < 0 {
		return -1
	}
	return (start + 1) % len(gas)
}
