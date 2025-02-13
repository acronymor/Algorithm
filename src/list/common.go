package list

type ListNode struct {
	Val  int
	Next *ListNode
}

func (ll *ListNode) ToHeadList(nums []int) *ListNode {
	var head = &ListNode{0, nil}
	var p *ListNode = head

	for _, num := range nums {
		p.Next = &ListNode{num, nil}
		p = p.Next
	}

	return head
}

func (ll *ListNode) ToNoHeadList(nums []int) *ListNode {
	return ll.ToHeadList(nums).Next
}
