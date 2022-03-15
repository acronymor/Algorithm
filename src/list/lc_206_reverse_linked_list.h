#include "list/common.h"

/**
 * @namespace list
 * @brief 反转链表
 */

namespace algo {
namespace list {
/**
 * @brief 反转链表
 *
 * @details
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 * 输入：head = []
 * 输出：[]
 *
 * @see [leetcode-206](https://leetcode.cn/problems/reverse-linked-list/)
 */

class ReverseList {
 public:
  ListNode<int>* reverseList1(ListNode<int>* head) {
    ListNode<int>* tmp_head = new ListNode<int>(-1);
    ListNode<int>* p = head;

    while (p != nullptr) {
      ListNode<int>* next = p->next;

      p->next = tmp_head->next;
      tmp_head->next = p;

      p = next;
    }

    p = tmp_head->next;
    delete tmp_head;

    return p;
  }

  ListNode<int>* reverseList2(ListNode<int>* head) {
    ListNode<int>* pre = nullptr;
    ListNode<int>* p = head;

    while (p != nullptr) {
      ListNode<int>* next = p->next;

      p->next = pre;
      pre = p;

      p = next;
    }

    return pre;
  }
};
}  // namespace list
}  // namespace algo