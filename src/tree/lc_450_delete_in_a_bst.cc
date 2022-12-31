#include "tree/lc_450_delete_in_a_bst.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class DeleteNodeTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new DeleteNode(); }

  void TearDown() override { delete exec; }

 protected:
  DeleteNode* exec{nullptr};
};

TEST_F(DeleteNodeTest, deleteNode) {
  std::vector<int> nums1 = {5, 3, 2, -1, -1, 4, -1, -1, 6, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->deleteNode(root1, 3);
  ASSERT_EQ(4, res1->left->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->deleteNode(root2, 0);
  ASSERT_EQ(nullptr, res2);
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
