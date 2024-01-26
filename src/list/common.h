#include <iostream>
#include <vector>
#include <cstdint>

namespace algo {
namespace list {
template <typename T>
struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(T x) : val(x), next(nullptr) {}
  ListNode(T x, ListNode* next) : val(x), next(next) {}

  T val;
  ListNode* next;
};

template <typename T>
ListNode<T>* ToHeadList(const std::vector<T>& nums) {
  ListNode<T>* head = new ListNode<T>(0);
  ListNode<T>* p = head;

  for (const T& num : nums) {
    p->next = new ListNode<T>(num);
    p = p->next;
  }

  return head;
}

template <typename T>
ListNode<T>* ToNoHeadList(const std::vector<T>& nums) {
  ListNode<T>* head = ToHeadList(nums);
  ListNode<T>* node = head->next;
  delete head;
  return node;
}

template <typename T>
void FreeList(ListNode<T>* head) {
  ListNode<T>* p = head;
  while (p != nullptr) {
    ListNode<T>* tmp = p;
    p = p->next;
    delete tmp;
  }
}

template <typename T>
ListNode<T>* ListAt(ListNode<T>* head, uint32_t pos) {
  ListNode<T>* p = head;
  if (head->val == 0) {
    p = p->next;
  }

  while (pos > 0 && p != nullptr) {
    pos--;
    p = p->next;
  }

  return p;
}
}  // namespace list
}  // namespace algo