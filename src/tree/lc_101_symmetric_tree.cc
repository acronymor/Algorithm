#include "tree/lc_101_symmetric_tree.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class IsSymmetricTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new IsSymmetric(); }

  void TearDown() override { delete exec; }

 protected:
  IsSymmetric* exec{nullptr};
};

TEST_F(IsSymmetricTest, isSymmetric) {
  std::vector<int> nums1 = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  ASSERT_TRUE(exec->isSymmetric(root1));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {1, 2, -1, 3, -1, -1, 2, -1, 3, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  ASSERT_FALSE(exec->isSymmetric(root2));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
