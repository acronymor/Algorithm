#include "list/common.h"

/**
 * @namespace list
 * @brief 移除链表元素
 */

namespace algo {
namespace list {

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

class RemoveElements {
 public:
  ListNode<int>* removeElements(ListNode<int>* head, int val) {
    ListNode<int>* tmp_head = new ListNode<int>(-1, head);
    ListNode<int>* pre = tmp_head;
    ListNode<int>* p = pre->next;

    while (p != nullptr) {
      if (p->val == val) {
        pre->next = p->next;
        delete p;
        p = pre->next;
      } else {
        pre = p;
        p = p->next;
      }
    }

    p = tmp_head->next;
    delete tmp_head;
    return p;
  }
};
}  // namespace list
}  // namespace algo