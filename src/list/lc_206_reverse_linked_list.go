package list

/**
 * @brief 反转链表
 *
 * @details
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 * 输入：head = []
 * 输出：[]
 *
 * @see [leetcode-206](https://leetcode.cn/problems/reverse-linked-list/)
 */

func reverseList(head *ListNode) *ListNode {
	var dummyHead = &ListNode{-1, nil}

	p := head

	for p != nil {
		q := p.Next

		p.Next = dummyHead.Next
		dummyHead.Next = p

		p = q
	}

	return dummyHead.Next
}
