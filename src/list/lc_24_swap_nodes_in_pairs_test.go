package list

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSwapPairs(t *testing.T) {
	toSlice := func(head *ListNode) []int {
		var res []int
		for p := head; p != nil; p = p.Next {
			res = append(res, p.Val)
		}
		return res
	}

	var ll *ListNode = &ListNode{0, nil}

	var res *ListNode = swapPairs(ll.ToNoHeadList([]int{1, 2, 3, 4}))
	assert.ElementsMatch(t, []int{2, 1, 4, 3}, toSlice(res))

	res = swapPairs(ll.ToNoHeadList([]int{}))
	assert.ElementsMatch(t, []int{}, toSlice(res))

	res = swapPairs(ll.ToNoHeadList([]int{1}))
	assert.ElementsMatch(t, []int{1}, toSlice(res))
}
