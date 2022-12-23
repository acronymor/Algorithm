#include "tree/lc_111_minimum_depth.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class MinDepthTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MinDepth(); }

  void TearDown() override { delete exec; }

 protected:
  MinDepth* exec{nullptr};
};

TEST_F(MinDepthTest, minDepth1) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_EQ(2, exec->minDepth1(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {2, -1, 3, -1, 4, -1, 5, -1, 6, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_EQ(5, exec->minDepth1(root2));
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  ASSERT_EQ(0, exec->minDepth1(root3));
  FreeBinaryTree(root3);
}

TEST_F(MinDepthTest, minDepth2) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_EQ(2, exec->minDepth2(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_EQ(0, exec->minDepth2(root2));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
