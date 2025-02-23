package algo

import "container/list"

/**
* @brief LRU 缓存
*
* @details
* 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
* 实现 LRUCache 类
* LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
* int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
* void put(int key, int value)
*   如果关键字 key 已经存在，则变更其数据值 value ；
*   如果不存在，则向缓存中插入该组 key-value 。
*   如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
*
*
* @par 示例
*
* 输入：["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
       [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
* 输出：[null, null, null, 1, null, -1, null, -1, 3, 4]
*
* @see [leetcode-146](https://leetcode.cn/problems/lru-cache/)
*/

type LRUCache struct {
	capacity int
	cache    map[int]*list.Element
	ll       *list.List
}

type Entry struct {
	key   int
	value int
}

func (c *LRUCache) Put(key int, value int) {
	entry := &Entry{key: key, value: value}

	if elem, ok := c.cache[key]; ok {
		elem.Value = entry
		c.ll.MoveToFront(elem)
		return
	}

	elem := c.ll.PushFront(entry)
	c.cache[key] = elem

	if len(c.cache) > c.capacity {
		if last := c.ll.Back(); last != nil {
			c.ll.Remove(last)
			delete(c.cache, last.Value.(*Entry).key)
		}
	}
}

func (c *LRUCache) Get(key int) int {
	if elem, ok := c.cache[key]; ok {
		c.ll.MoveToFront(elem)
		return elem.Value.(*Entry).value
	}

	return -1
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity: capacity,
		cache:    make(map[int]*list.Element, capacity),
		ll:       list.New(),
	}
}
