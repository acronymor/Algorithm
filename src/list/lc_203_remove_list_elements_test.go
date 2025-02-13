package list

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRemoveElements(t *testing.T) {
	toSlice := func(head *ListNode) []int {
		var res []int
		for p := head; p != nil; p = p.Next {
			res = append(res, p.Val)
		}
		return res
	}

	var ll *ListNode = &ListNode{0, nil}
	var head *ListNode = removeElements(ll.ToNoHeadList([]int{1, 2, 6, 3, 4, 5, 6}), 6)
	assert.ElementsMatch(t, []int{1, 2, 3, 4, 5}, toSlice(head))

	head = removeElements(ll.ToNoHeadList([]int{7, 7, 7, 7}), 7)
	assert.ElementsMatch(t, []int{}, toSlice(head))
}
