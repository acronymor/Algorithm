package list

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRemoveNthFromEnd(t *testing.T) {
	toSlice := func(head *ListNode) []int {
		var res []int
		for p := head; p != nil; p = p.Next {
			res = append(res, p.Val)
		}
		return res
	}

	var ll *ListNode = &ListNode{0, nil}

	var res *ListNode = removeNthFromEnd(ll.ToNoHeadList([]int{1, 2, 3, 4, 5}), 2)
	assert.ElementsMatch(t, []int{1, 2, 3, 5}, toSlice(res))

	res = removeNthFromEnd(ll.ToNoHeadList([]int{1}), 1)
	assert.ElementsMatch(t, []int{}, toSlice(res))

	res = removeNthFromEnd(ll.ToNoHeadList([]int{1, 2}), 1)
	assert.ElementsMatch(t, []int{1}, toSlice(res))
}
