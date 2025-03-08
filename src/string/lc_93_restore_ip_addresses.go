package string

import (
	"strconv"
	"strings"
)

/**
 * @brief 复原 IP 地址
 *
 * @details
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP
 * 地址。 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入
 * '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 *
 * @par 示例
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 * @see [leetcode-93](https://leetcode.cn/problems/restore-ip-addresses/)
 */
func restoreIpAddresses(s string) []string {
	var check func(ss string) bool
	check = func(ss string) bool {
		if len(ss) == 0 {
			return false
		}

		num, _ := strconv.Atoi(ss)
		return num >= 0 && num <= 255
	}

	var res []string = make([]string, 0)
	var ans []string = make([]string, 0)

	var backtrace func(idx int, split int)

	backtrace = func(idx int, segment int) {
		if idx == len(s) && segment == 4 {
			tmp := strings.Join(ans, ".")
			res = append(res, tmp)
			return
		}

		if idx == len(s) || segment == 4 {
			return
		}

		for i := idx; i < len(s); i++ {
			if i != idx && s[idx] == '0' {
				break
			}

			ss := s[idx : i+1]
			if check(ss) {
				ans = append(ans, ss)
				backtrace(i+1, segment+1)
				ans = ans[:len(ans)-1]
			}
		}
	}

	backtrace(0, 0)

	return res
}
