package list

/**
 * @brief 两两交换链表中的节点
 *
 * @details
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 * 输入：head = []
 * 输出：[]
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 * @see [leetcode-24](https://leetcode.cn/problems/swap-nodes-in-pairs/)
 */

func swapPairs(head *ListNode) *ListNode {
	var dummyHead *ListNode = &ListNode{-1, head}

	p := dummyHead
	q := p.Next

	for q != nil && q.Next != nil {
		r := q.Next
		s := r.Next

		q.Next = s
		r.Next = q
		p.Next = r

		p = q
		q = p.Next
	}

	return dummyHead.Next
}
