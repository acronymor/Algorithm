package list

/**
 * @brief 反转链表 II
 *
 * @details
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 *
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 *
 * @see [leetcode-92](https://leetcode.cn/problems/reverse-linked-list-ii/)
 */

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	i := 1
	dummyHead := &ListNode{Val: -1, Next: head}
	pre := dummyHead

	for ; i < left; i++ {
		pre = pre.Next
	}

	p := pre.Next
	pre.Next = nil

	for ; i <= right; i++ {
		q := p.Next

		p.Next = pre.Next
		pre.Next = p
		p = q
	}

	for pre.Next != nil {
		pre = pre.Next
	}
	pre.Next = p

	return dummyHead.Next
}
