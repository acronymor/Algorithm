#include "tree/lc_515_find_largest_value.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class LargestValuesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LargestValues(); }

  void TearDown() override { delete exec; }

 protected:
  LargestValues* exec{nullptr};
};

TEST_F(LargestValuesTest, largestValues) {
  std::vector<int> nums1 = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<int> res1 = exec->largestValues(root1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(3, res1.at(1));
  ASSERT_EQ(9, res1.at(2));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {1, 2, -1, -1, 3, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<int> res2 = exec->largestValues(root2);
  ASSERT_EQ(1, res2.at(0));
  ASSERT_EQ(3, res2.at(1));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
