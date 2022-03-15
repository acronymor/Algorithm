#include "list/lc_24_swap_nodes_in_pairs.h"

#include "gtest/gtest.h"

namespace algo {
namespace list {
class SwapPairsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SwapPairs(); }

  void TearDown() override { delete exec; }

 protected:
  SwapPairs* exec{nullptr};
};

TEST_F(SwapPairsTest, removeElements) {
  std::vector<int> nums1 = {1, 2, 3, 4};
  ListNode<int>* head1 = ToNoHeadList(nums1);
  head1 = exec->swapPairs(head1);
  ASSERT_EQ(2, ListAt(head1, 0)->val);
  ASSERT_EQ(4, ListAt(head1, 2)->val);
  FreeList(head1);

  std::vector<int> nums2 = {};
  ListNode<int>* head2 = ToNoHeadList(nums2);
  head2 = exec->swapPairs(head2);
  ASSERT_EQ(nullptr, head2);
  FreeList(head2);

  std::vector<int> nums3 = {1};
  ListNode<int>* head3 = ToNoHeadList(nums3);
  head3 = exec->swapPairs(head3);
  ASSERT_EQ(1, head3->val);
  FreeList(head3);
}
}  // namespace list
}  // namespace algo
