package list

/**
 * @brief 移除链表元素
 *
 * @details
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *
 * @par 示例
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 * @see [leetcode-203](https://leetcode.cn/problems/remove-linked-list-elements/)
 */

func removeElements(head *ListNode, val int) *ListNode {
	var dummyHead *ListNode = &ListNode{-1, head}
	var p *ListNode = dummyHead
	var q *ListNode = p.Next

	for q != nil {
		if q.Val == val {
			p.Next = q.Next
			q = p.Next
		} else {
			p = q
			q = q.Next
		}
	}

	return dummyHead.Next
}
