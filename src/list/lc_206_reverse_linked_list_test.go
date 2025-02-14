package list

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestReverseList(t *testing.T) {
	toSlice := func(head *ListNode) []int {
		var res []int
		for p := head; p != nil; p = p.Next {
			res = append(res, p.Val)
		}
		return res
	}

	var ll *ListNode = &ListNode{0, nil}

	var res *ListNode = reverseList(ll.ToNoHeadList([]int{1, 2, 3, 4, 5}))
	assert.ElementsMatch(t, []int{5, 4, 3, 2, 1}, toSlice(res))

	res = reverseList(ll.ToNoHeadList([]int{1, 2}))
	assert.ElementsMatch(t, []int{2, 1}, toSlice(res))

	res = reverseList(ll.ToNoHeadList([]int{}))
	assert.ElementsMatch(t, []int{}, toSlice(res))
}
