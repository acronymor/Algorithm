package array

import "math/rand"

/**
 * @brief O(1) 时间插入、删除和获取随机元素
 *
 * @details
 * 实现RandomizedSet 类：
 * RandomizedSet() 初始化 RandomizedSet 对象
 * bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
 * bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
 * int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
 * 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
 *
 * @par 示例
 *
 * 输入：["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 *      [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出：[null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * @see [leetcode-380](https://leetcode.cn/problems/insert-delete-getrandom-o1/)
 */

type RandomizedSet struct {
	nums  []int
	table map[int]int
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		nums:  make([]int, 0),
		table: make(map[int]int, 1000),
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.table[val]; ok {
		return false
	}

	this.table[val] = len(this.nums)
	this.nums = append(this.nums, val)

	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	pos, ok := this.table[val]
	if !ok {
		return false
	}

	last := len(this.nums) - 1
	this.table[this.nums[last]] = pos
	this.nums[pos] = this.nums[last]
	this.nums = this.nums[:last]
	delete(this.table, val)

	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.nums[rand.Intn(len(this.nums))]
}
