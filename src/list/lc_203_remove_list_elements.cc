#include "gtest/gtest.h"
#include "list/lc_203_remove_list_elements.h"

namespace algo {
namespace list {
class RemoveElementsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RemoveElements(); }

  void TearDown() override { delete exec; }

 protected:
  RemoveElements* exec{nullptr};
};

TEST_F(RemoveElementsTest, removeElements) {
  std::vector<int> nums1 = {1, 2, 6, 3, 4, 5, 6};
  ListNode<int>* head1 = ToNoHeadList(nums1);
  head1 = exec->removeElements(head1, 6);
  ASSERT_EQ(1, ListAt(head1, 0)->val);
  ASSERT_EQ(3, ListAt(head1, 2)->val);
  ASSERT_EQ(5, ListAt(head1, 4)->val);
  FreeList(head1);

  std::vector<int> nums2 = {};
  ListNode<int>* head2 = ToNoHeadList(nums2);
  head2 = exec->removeElements(head2, 1);
  ASSERT_EQ(nullptr, head2);
  FreeList(head2);

  std::vector<int> nums3 = {7, 7, 7, 7};
  ListNode<int>* head3 = ToNoHeadList(nums3);
  head3 = exec->removeElements(head3, 7);
  ASSERT_EQ(nullptr, head3);
  FreeList(head3);
}
}  // namespace list
}  // namespace algo
