#include "tree/lc_654_maximum_binary_tree.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class MaximumBinaryTreeTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaximumBinaryTree(); }

  void TearDown() override { delete exec; }

 protected:
  MaximumBinaryTree* exec{nullptr};
};

TEST_F(MaximumBinaryTreeTest, construct1) {
  std::vector<int> nums1 = {3, 2, 1, 6, 0, 5};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->constructMaximumBinaryTree1(nums1);
  ASSERT_EQ(6, res1->val);
  ASSERT_EQ(3, res1->left->val);
  ASSERT_EQ(5, res1->right->val);
  FreeBinaryTree(root1);
}

TEST_F(MaximumBinaryTreeTest, construct2) {
  std::vector<int> nums1 = {3, 2, 1, 6, 0, 5};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->constructMaximumBinaryTree2(nums1);
  ASSERT_EQ(6, res1->val);
  ASSERT_EQ(3, res1->left->val);
  ASSERT_EQ(5, res1->right->val);
  FreeBinaryTree(root1);
}
}  // namespace tree
}  // namespace algo
