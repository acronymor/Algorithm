#include "list/lc_19_remove_nth_node.h"

#include "gtest/gtest.h"

namespace algo {
namespace list {
class RemoveNthFromEndTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RemoveNthFromEnd(); }

  void TearDown() override { delete exec; }

 protected:
  RemoveNthFromEnd* exec{nullptr};
};

TEST_F(RemoveNthFromEndTest, removeElements) {
  std::vector<int> nums1 = {1, 2, 3, 4, 5};
  ListNode<int>* head1 = ToNoHeadList(nums1);
  head1 = exec->removeNthFromEnd(head1, 2);
  ASSERT_EQ(5, ListAt(head1, 3)->val);
  FreeList(head1);

  std::vector<int> nums2 = {1};
  ListNode<int>* head2 = ToNoHeadList(nums2);
  head2 = exec->removeNthFromEnd(head2, 1);
  ASSERT_TRUE(nullptr == head2);
  FreeList(head2);

  std::vector<int> nums3 = {1, 2};
  ListNode<int>* head3 = ToNoHeadList(nums3);
  head3 = exec->removeNthFromEnd(head3, 1);
  ASSERT_EQ(1, ListAt(head3, 0)->val);
  FreeList(head3);
}
}  // namespace list
}  // namespace algo
