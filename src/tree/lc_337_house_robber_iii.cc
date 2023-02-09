#include "tree/lc_337_house_robber_iii.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class RobIIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RobIII(); }

  void TearDown() override { delete exec; }

 protected:
  RobIII* exec{nullptr};
};

TEST_F(RobIIITest, solve) {
  std::vector<int> nums1 = {3, 2, -1, 3, -1, -1, 3, -1, 1, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_EQ(7, exec->solve(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {3, 4, 1, -1, -1, 3, -1, -1, 5, -1, 1, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_EQ(9, exec->solve(root2));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo