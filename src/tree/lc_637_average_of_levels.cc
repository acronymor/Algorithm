#include "tree/lc_637_average_of_levels.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class AverageOfLevelsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new AverageOfLevels(); }

  void TearDown() override { delete exec; }

 protected:
  AverageOfLevels* exec{nullptr};
};

TEST_F(AverageOfLevelsTest, averageOfLevels) {
  std::vector<int> nums1 = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<double> res1 = exec->averageOfLevels(root1);
  ASSERT_EQ(3.00, res1.at(0));
  ASSERT_EQ(14.50, res1.at(1));
  ASSERT_EQ(11.00, res1.at(2));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {3, 9, 15, -1, -1, 7, -1, -1, 20, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<double> res2 = exec->averageOfLevels(root2);
  ASSERT_EQ(3.00, res2.at(0));
  ASSERT_EQ(14.50, res2.at(1));
  ASSERT_EQ(11.00, res2.at(2));
  FreeBinaryTree(root2);
}
}  // namespace tree
}  // namespace algo
