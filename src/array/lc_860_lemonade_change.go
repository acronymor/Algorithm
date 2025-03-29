package array

/**
 * @brief 柠檬水找零
 *
 * @details
 * 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
 * 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
 * 注意，一开始你手头没有任何零钱。
 * 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
 *
 * @par 示例
 * 输入：bills = [5,5,5,10,20]
 * 输出：true
 *
 * 输入：bills = [5,5,10,10,20]
 * 输出：false
 *
 * @see [leetcode-860](https://leetcode.cn/problems/lemonade-change/)
 */

func lemonadeChange(bills []int) bool {
	var table map[int]int = make(map[int]int, 3)
	table[5] = 0
	table[10] = 0
	table[20] = 0

	for _, bill := range bills {
		table[bill]++
		if bill == 10 {
			if cnt, _ := table[5]; cnt == 0 {
				return false
			}
			table[5]--
		} else if bill == 20 {
			cnt10, _ := table[10]
			cnt5, _ := table[5]
			if cnt5 != 0 && cnt10 != 0 {
				table[5]--
				table[10]--
			} else if cnt5 >= 3 {
				table[5] -= 3
			} else {
				return false
			}
		}
	}

	return true
}
