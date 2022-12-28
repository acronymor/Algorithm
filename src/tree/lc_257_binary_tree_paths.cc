#include "tree/lc_257_binary_tree_paths.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class BinaryTreePathsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new BinaryTreePaths(); }

  void TearDown() override { delete exec; }

 protected:
  BinaryTreePaths* exec{nullptr};
};

TEST_F(BinaryTreePathsTest, invertTree1) {
  std::vector<int> nums1 = {1, 2, -1, 5, -1, -1, 3, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<std::string> res1 = exec->binaryTreePaths(root1);
  ASSERT_EQ("1->2->5", res1.at(0));
  ASSERT_EQ("1->3", res1.at(1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {1, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<std::string> res2 = exec->binaryTreePaths(root2);
  ASSERT_EQ("1", res2.at(0));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
