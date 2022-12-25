#include "tree/lc_226_invert_binary_tree.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class InvertTreeTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new InvertTree(); }

  void TearDown() override { delete exec; }

 protected:
  InvertTree* exec{nullptr};
};

TEST_F(InvertTreeTest, invertTree1) {
  std::vector<int> nums1 = {4, 2, 1, -1, -1, 3, -1, -1, 7, 6, -1, -1, 9, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->invertTree1(root1);
  ASSERT_EQ(4, res1->val);
  ASSERT_EQ(2, res1->right->val);
  ASSERT_EQ(7, res1->left->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {2, 1, -1, -1, 3, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->invertTree1(root2);
  ASSERT_EQ(2, res2->val);
  ASSERT_EQ(1, res2->right->val);
  ASSERT_EQ(3, res2->left->val);
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  TreeNode<int>* res3 = exec->invertTree1(root3);
  ASSERT_EQ(root3, res3);
  FreeBinaryTree(root3);
}

TEST_F(InvertTreeTest, invertTree2) {
  std::vector<int> nums1 = {4, 2, 1, -1, -1, 3, -1, -1, 7, 6, -1, -1, 9, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->invertTree2(root1);
  ASSERT_EQ(4, res1->val);
  ASSERT_EQ(2, res1->right->val);
  ASSERT_EQ(7, res1->left->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {2, 1, -1, -1, 3, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->invertTree2(root2);
  ASSERT_EQ(2, res2->val);
  ASSERT_EQ(1, res2->right->val);
  ASSERT_EQ(3, res2->left->val);
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  TreeNode<int>* res3 = exec->invertTree2(root3);
  ASSERT_EQ(root3, res3);
  FreeBinaryTree(root3);
}

TEST_F(InvertTreeTest, invertTree3) {
  std::vector<int> nums1 = {4, 2, 1, -1, -1, 3, -1, -1, 7, 6, -1, -1, 9, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->invertTree3(root1);
  ASSERT_EQ(4, res1->val);
  ASSERT_EQ(2, res1->right->val);
  ASSERT_EQ(7, res1->left->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {2, 1, -1, -1, 3, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->invertTree3(root2);
  ASSERT_EQ(2, res2->val);
  ASSERT_EQ(1, res2->right->val);
  ASSERT_EQ(3, res2->left->val);
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  TreeNode<int>* res3 = exec->invertTree3(root3);
  ASSERT_EQ(root3, res3);
  FreeBinaryTree(root3);
}
}  // namespace tree
}  // namespace algo
