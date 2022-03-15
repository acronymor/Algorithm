#include "list/lc_206_reverse_linked_list.h"

#include "gtest/gtest.h"

namespace algo {
namespace list {
class ReverseListTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ReverseList(); }

  void TearDown() override { delete exec; }

 protected:
  ReverseList* exec{nullptr};
};

TEST_F(ReverseListTest, reverseList1) {
  std::vector<int> nums1 = {1, 2, 3, 4, 5};
  ListNode<int>* head1 = ToNoHeadList(nums1);
  head1 = exec->reverseList1(head1);
  ASSERT_EQ(5, ListAt(head1, 0)->val);
  ASSERT_EQ(3, ListAt(head1, 2)->val);
  ASSERT_EQ(1, ListAt(head1, 4)->val);
  FreeList(head1);

  std::vector<int> nums2 = {};
  ListNode<int>* head2 = ToNoHeadList(nums2);
  head2 = exec->reverseList1(head2);
  ASSERT_TRUE(head2 == nullptr);
  FreeList(head2);
}

TEST_F(ReverseListTest, reverseList2) {
  std::vector<int> nums1 = {1, 2, 3, 4, 5};
  ListNode<int>* head1 = ToNoHeadList(nums1);
  head1 = exec->reverseList2(head1);
  ASSERT_EQ(5, ListAt(head1, 0)->val);
  ASSERT_EQ(3, ListAt(head1, 2)->val);
  ASSERT_EQ(1, ListAt(head1, 4)->val);
  FreeList(head1);

  std::vector<int> nums2 = {};
  ListNode<int>* head2 = ToNoHeadList(nums2);
  head2 = exec->reverseList2(head2);
  ASSERT_TRUE(head2 == nullptr);
  FreeList(head2);
}

}  // namespace list
}  // namespace algo
