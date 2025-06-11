package corp

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

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

func TestPrintNTurns(t *testing.T) {
	row, col := 2, 7
	sentence := "Hello world"
	res := printNTurns(row, col, sentence)
	assert.Equal(t, 1, res)

	row, col = 2, 7
	sentence = "H"
	res = printNTurns(row, col, sentence)
	assert.Equal(t, 8, res)

	row, col = 2, 7
	sentence = "abcdefghijk"
	res = printNTurns(row, col, sentence)
	assert.Equal(t, 0, res)
}
