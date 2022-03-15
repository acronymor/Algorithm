#include "list/common.h"

/**
 * @namespace list
 * @brief 两两交换链表中的节点
 */

namespace algo {
namespace list {
/**
 * @brief 两两交换链表中的节点
 *
 * @details
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 * 输入：head = []
 * 输出：[]
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 * @see [leetcode-24](https://leetcode.cn/problems/swap-nodes-in-pairs/)
 */

class SwapPairs {
 public:
  ListNode<int>* swapPairs(ListNode<int>* head) {
    ListNode<int>* tmp_head = new ListNode<int>(0, head);

    ListNode<int>* pre = tmp_head;
    ListNode<int>* p = pre->next;

    while (p != nullptr && p->next != nullptr) {
      ListNode<int>* q = p->next;

      p->next = q->next;
      q->next = p;
      pre->next = q;

      pre = p;
      p = p->next;
    }

    head = tmp_head->next;
    delete tmp_head;

    return head;
  }
};
}  // namespace list
}  // namespace algo