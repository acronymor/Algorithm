#include "tree/lc_701_insert_into_bst.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class InsertIntoBSTTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new InsertIntoBST(); }

  void TearDown() override { delete exec; }

 protected:
  InsertIntoBST* exec{nullptr};
};

TEST_F(InsertIntoBSTTest, insertIntoBST1) {
  std::vector<int> nums1 = {4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->insertIntoBST1(root1, 5);
  ASSERT_EQ(5, res1->right->left->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->insertIntoBST1(root2, 5);
  ASSERT_EQ(5, res2->val);
  FreeBinaryTree(root2);
}

TEST_F(InsertIntoBSTTest, insertIntoBST2) {
  std::vector<int> nums1 = {4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->insertIntoBST2(root1, 5);
  ASSERT_EQ(5, res1->right->left->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->insertIntoBST2(root2, 5);
  ASSERT_EQ(5, res2->val);
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
