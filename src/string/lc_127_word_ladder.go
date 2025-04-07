package string

import (
	"container/list"
)

/**
 * @brief 单词接龙
 *
 * @details
 * 字典 wordList 中从单词 beginWord 到 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
 * 每一对相邻的单词只差一个字母。
 *  对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
 *
 * @par 示例
 *
 * 示例 1
 * 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 *
 * 示例 2
 * 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * 输出：0
 * 解释：endWord "cog" 不在字典中，所以无法进行转换。
 *
 * @see [leetcode-127](https://leetcode.cn/problems/word-ladder/)
 */

func ladderLength(beginWord string, endWord string, wordList []string) int {
	canConvert := func(s1 string, s2 string) bool {
		var cnt = 0

		for i := 0; i < len(s1); i++ {
			if s1[i] != s2[i] {
				cnt++
			}
		}

		return cnt == 1
	}

	var table map[string]int = make(map[string]int, len(wordList))
	for idx, word := range wordList {
		table[word] = idx
	}

	if _, ok := table[endWord]; !ok {
		return 0
	}

	var visited []bool = make([]bool, len(wordList))
	var count = 0

	queue := list.New()
	queue.PushBack(beginWord)
	if idx, ok := table[beginWord]; ok {
		visited[idx] = true
	}

	for queue.Len() > 0 {
		var size int = queue.Len()
		count++
		for i := 0; i < size; i++ {
			item := queue.Front()
			queue.Remove(item)

			for j := 0; j < len(wordList); j++ {
				if visited[j] {
					continue
				}

				var s string = wordList[j]
				if !canConvert(item.Value.(string), s) {
					continue
				}

				if s == endWord {
					return count + 1
				}

				visited[j] = true
				queue.PushBack(s)
			}
		}
	}

	return 0
}
