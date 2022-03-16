#include "list/common.h"

/**
 * @namespace list
 * @brief 删除链表的倒数第 N 个结点
 */

namespace algo {
namespace list {
/**
 * @brief 删除链表的倒数第 N 个结点
 *
 * @details
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 * @par 示例
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 * @see [leetcode-19](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)
 */

class RemoveNthFromEnd {
 public:
  ListNode<int>* removeNthFromEnd(ListNode<int>* head, int n) {
    ListNode<int>* tmp_head = new ListNode<int>(-1, head);
    ListNode<int>* pre = tmp_head;
    ListNode<int>* p = tmp_head;

    while (n >= 0 && p != nullptr) {
      p = p->next;
      n--;
    }

    while (p != nullptr) {
      pre = pre->next;
      p = p->next;
    }

    p = pre->next;
    pre->next = p->next;
    delete p;

    return tmp_head->next;
  }
};
}  // namespace list
}  // namespace algo