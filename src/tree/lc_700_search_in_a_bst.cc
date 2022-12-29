#include "tree/lc_700_search_in_a_bst.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class SearchBSTTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SearchBST(); }

  void TearDown() override { delete exec; }

 protected:
  SearchBST* exec{nullptr};
};

TEST_F(SearchBSTTest, searchBST) {
  std::vector<int> nums1 = {4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  TreeNode<int>* res1 = exec->searchBST(root1, 2);
  ASSERT_EQ(2, res1->val);
  ASSERT_EQ(1, res1->left->val);
  ASSERT_EQ(3, res1->right->val);
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {4, 2, 1, -1, -1, 3, -1, -1, 7, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  TreeNode<int>* res2 = exec->searchBST(root2, 5);
  ASSERT_EQ(nullptr, res2);
  FreeBinaryTree(root2);
}

}  // namespace tree
}  // namespace algo
