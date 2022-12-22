#include "tree/lc_107_levelorder_traversal_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class LevelorderTraversalIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LevelorderTraversalII(); }

  void TearDown() override { delete exec; }

 protected:
  LevelorderTraversalII* exec{nullptr};
};

TEST_F(LevelorderTraversalIITest, levelorderTraversal) {
  std::vector<int> nums1 = {1, -1, 2, 3, -1, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<std::vector<int>> res1 = exec->levelorderTraversal(root1);
  ASSERT_EQ(3, res1.at(0).at(0));
  ASSERT_EQ(2, res1.at(1).at(0));
  ASSERT_EQ(1, res1.at(2).at(0));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<std::vector<int>> res2 = exec->levelorderTraversal(root2);
  ASSERT_EQ(0, res2.size());
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {1, -1, -1};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  std::vector<std::vector<int>> res3 = exec->levelorderTraversal(root3);
  ASSERT_EQ(1, res3.at(0).at(0));
  FreeBinaryTree(root3);

  std::vector<int> nums4 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root4 = ToBinaryTree(nums4);
  std::vector<std::vector<int>> res4 = exec->levelorderTraversal(root4);
  ASSERT_EQ(15, res4.at(0).at(0));
  ASSERT_EQ(9, res4.at(1).at(0));
  ASSERT_EQ(3, res4.at(2).at(0));
  FreeBinaryTree(root4);
}
}  // namespace tree
}  // namespace algo
