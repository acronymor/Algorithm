package list

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestReverseBetween(t *testing.T) {
	toSlice := func(head *ListNode) []int {
		var res []int
		for p := head; p != nil; p = p.Next {
			res = append(res, p.Val)
		}
		return res
	}

	var ll *ListNode = &ListNode{0, nil}

	var res *ListNode = reverseBetween(ll.ToNoHeadList([]int{1, 2, 3, 4, 5}), 2, 4)
	assert.ElementsMatch(t, []int{1, 4, 3, 2, 5}, toSlice(res))

	res = reverseBetween(ll.ToNoHeadList([]int{5}), 1, 1)
	assert.ElementsMatch(t, []int{5}, toSlice(res))
}
