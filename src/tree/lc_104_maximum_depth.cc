#include "tree/lc_104_maximum_depth.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class MaxDepthTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxDepth(); }

  void TearDown() override { delete exec; }

 protected:
  MaxDepth* exec{nullptr};
};

TEST_F(MaxDepthTest, maxDepth1) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_EQ(3, exec->maxDepth1(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_EQ(0, exec->maxDepth1(root2));
  FreeBinaryTree(root2);
}

TEST_F(MaxDepthTest, maxDepth2) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_EQ(3, exec->maxDepth2(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_EQ(0, exec->maxDepth2(root2));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
