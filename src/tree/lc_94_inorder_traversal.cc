#include "tree/lc_94_inorder_traversal.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class InorderTraversalTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new InorderTraversal(); }

  void TearDown() override { delete exec; }

 protected:
  InorderTraversal* exec{nullptr};
};

TEST_F(InorderTraversalTest, inorderTraversal1) {
  std::vector<int> nums1 = {1, -1, 2, 3, -1, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<int> res1 = exec->inorderTraversal1(root1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(3, res1.at(1));
  ASSERT_EQ(2, res1.at(2));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<int> res2 = exec->inorderTraversal1(root2);
  ASSERT_EQ(0, res2.size());
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {1, -1, -1};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  std::vector<int> res3 = exec->inorderTraversal1(root3);
  ASSERT_EQ(1, res3.at(0));
  FreeBinaryTree(root3);
}

TEST_F(InorderTraversalTest, inorderTraversal2) {
  std::vector<int> nums1 = {1, -1, 2, 3, -1, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<int> res1 = exec->inorderTraversal2(root1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(3, res1.at(1));
  ASSERT_EQ(2, res1.at(2));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<int> res2 = exec->inorderTraversal2(root2);
  ASSERT_EQ(0, res2.size());
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {1, -1, -1};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  std::vector<int> res3 = exec->inorderTraversal2(root3);
  ASSERT_EQ(1, res3.at(0));
  FreeBinaryTree(root3);
}
}  // namespace tree
}  // namespace algo
