package array

/**
 * @brief 单词拆分
 *
 * @details
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 *
 * @par 示例
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 *
 * @see [leetcode-139](https://leetcode.cn/problems/word-break/)
 */

func wordBreak(s string, wordDict []string) bool {
	var wordDictSet map[string]bool = make(map[string]bool, len(wordDict))
	for _, word := range wordDict {
		wordDictSet[word] = true
	}

	var dp []bool = make([]bool, len(s)+1)
	dp[0] = true

	for j := 1; j <= len(s); j++ {
		for i := 0; i < j; i++ {
			if dp[i] && wordDictSet[s[i:j]] {
				dp[j] = true
			}
		}
	}

	return dp[len(s)]
}
