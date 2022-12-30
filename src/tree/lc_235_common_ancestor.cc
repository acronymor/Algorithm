#include "tree/lc_235_common_ancestor.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class LowestCommonAncestorTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LowestCommonAncestor(); }

  void TearDown() override { delete exec; }

 protected:
  LowestCommonAncestor* exec{nullptr};
};

TEST_F(LowestCommonAncestorTest, lowestCommonAncestor1) {
  std::vector<int> nums1 = {6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->lowestCommonAncestor1(root1, root1->left, root1->right);
  ASSERT_EQ(6, res1->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->lowestCommonAncestor1(root2, root2->left, root2->left->right);
  ASSERT_EQ(2, res2->val);
  FreeBinaryTree(root2);
}

TEST_F(LowestCommonAncestorTest, lowestCommonAncestor2) {
  std::vector<int> nums1 = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->lowestCommonAncestor2(root1, root1->left, root1->right);
  ASSERT_EQ(3, res1->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->lowestCommonAncestor2(root2, root2->left, root2->left->right->left);
  ASSERT_EQ(5, res2->val);
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {1, 2, -1, -1, -1};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  TreeNode<int>* res3 = exec->lowestCommonAncestor2(root3, root3, root3->left);
  ASSERT_EQ(1, res3->val);
  FreeBinaryTree(root3);

  std::vector<int> nums4 = {37, -34, -1, -100, -1, -1, -48, -101, -1, -1, 48, -54, -71, -1, -1, -22, -1, 8, -1, -1, -1};
  TreeNode<int>* root4 = ToBinaryTree(nums4);
  TreeNode<int>* res4 = exec->lowestCommonAncestor2(root4, root4->right->right, root4->right->right->left->left);
  ASSERT_EQ(48, res4->val);
  FreeBinaryTree(root4);
}
}  // namespace tree
}  // namespace algo
