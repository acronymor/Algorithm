package corp

import "strings"

/**
 * @brief 打印 n 轮字符串
 *
 * @details
 * 给你一个文件，它有 row*col 个格子，每个格子只能打印一个字符。这个文件里，给定的句子最多能打印几遍？
 * 1. 一个单词不能打印在两行
 * 2. 句子里的单词不能打乱顺序
 * 3. 在同一行里，连续的两个单词，需要用一个空格隔开
 * 输入保证
 * 1. 句子里的单词数N，不会超过 100
 * 2. 每个单词长度大于0，小于 10
 *
 * @par 示例
 * Input：
 * row = 2
 * col = 7
 * sentence = "Hello world"
 *
 * Output:
 * 1
 */

func printNTurns(row, col int, sentence string) int {
	words := strings.Split(sentence, " ")
	i, j := 0, 0

	cnt, lineLength := 0, 0

	for {
		j = j % len(words)
		wordLen := len(words[j])
		if wordLen > col {
			return 0
		}

		lineLength += wordLen
		if lineLength > col {
			lineLength = wordLen
			i++
		}
		lineLength += 1

		if i == row {
			break
		}

		if j%len(words) == 0 {
			cnt++
		}

		j++
	}

	return cnt
}
