#include "tree/lc_404_sum_of_left_leaves.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class SumOfLeftLeavesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SumOfLeftLeaves(); }

  void TearDown() override { delete exec; }

 protected:
  SumOfLeftLeaves* exec{nullptr};
};

TEST_F(SumOfLeftLeavesTest, largestValues) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  int res1 = exec->sumOfLeftLeaves(root1);
  ASSERT_EQ(24, res1);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {1, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  int res2 = exec->sumOfLeftLeaves(root2);
  ASSERT_EQ(0, res2);
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  int res3 = exec->sumOfLeftLeaves(root3);
  ASSERT_EQ(4, res3);
  FreeBinaryTree(root3);
}
}  // namespace tree
}  // namespace algo
