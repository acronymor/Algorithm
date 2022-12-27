#include "tree/lc_110_balanced_binary_tree.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class IsBalancedTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IsBalanced(); }

  void TearDown() override { delete exec; }

 protected:
  IsBalanced* exec{nullptr};
};

TEST_F(IsBalancedTest, isBalanced) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_TRUE(exec->isBalanced(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {1, 2, 3, 4, -1, -1, 4, -1, -1, 3, -1, -1, 2, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_FALSE(exec->isBalanced(root2));
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  ASSERT_TRUE(exec->isBalanced(root3));
  FreeBinaryTree(root3);
}
}  // namespace tree
}  // namespace algo