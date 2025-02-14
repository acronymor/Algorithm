package list

/**
 * @brief 删除链表的倒数第 N 个结点
 *
 * @details
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 * @see [leetcode-19](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)
 */

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	var dummyHead *ListNode = &ListNode{0, head}

	var p *ListNode = dummyHead
	var q *ListNode = dummyHead

	for ; n >= 0; n-- {
		q = q.Next
	}

	for q != nil {
		p = p.Next
		q = q.Next
	}

	p.Next = p.Next.Next

	return dummyHead.Next
}
