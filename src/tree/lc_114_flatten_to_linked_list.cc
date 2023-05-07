#include "tree/lc_114_flatten_to_linked_list.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class FlattenToLinkedListTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FlattenToLinkedList(); }

  void TearDown() override { delete exec; }

 protected:
  FlattenToLinkedList* exec{nullptr};
};

TEST_F(FlattenToLinkedListTest, flatten) {
  std::vector<int> nums1 = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  exec->flatten(root1);
  TreeNode<int>* node1 = root1;
  for (int i = 1; i <= 6; i++) {
    ASSERT_EQ(i, node1->val);
    node1 = node1->right;
  }
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {0, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  exec->flatten(root2);
  ASSERT_EQ(0, root2->val);
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  exec->flatten(root3);
  ASSERT_EQ(nullptr, root3);
  FreeBinaryTree(root3);
}
}  // namespace tree
}  // namespace algo
