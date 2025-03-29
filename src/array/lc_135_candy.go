package array

/**
 * @brief 分发糖果
 *
 * @details
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 * 你需要按照以下要求，给这些孩子分发糖果：
 * 每个孩子至少分配到 1 个糖果。
 * 相邻两个孩子评分更高的孩子会获得更多的糖果。
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 *
 * @par 示例
 *
 * 输入: ratings = [1,0,2]
 * 输出: 5
 *
 * 输入: ratings = [1,2,2]
 * 输出: 4
 *
 * @see [leetcode-135](https://leetcode.cn/problems/candy/)
 */

func candy(ratings []int) int {
	var res []int = make([]int, len(ratings))

	for i := 0; i < len(ratings); i++ {
		res[i] = 1
	}

	for i := 1; i < len(ratings); i++ {
		if ratings[i] > ratings[i-1] {
			res[i] = res[i-1] + 1
		}
	}

	for i := len(ratings) - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] {
			res[i] = max(res[i], res[i+1]+1)
		}
	}

	var ans int = 0
	for i := 0; i < len(res); i++ {
		ans += res[i]
	}

	return ans
}
