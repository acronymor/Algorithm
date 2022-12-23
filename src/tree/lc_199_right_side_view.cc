#include "tree/lc_199_right_side_view.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class RightSideViewTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RightSideView(); }

  void TearDown() override { delete exec; }

 protected:
  RightSideView* exec{nullptr};
};

TEST_F(RightSideViewTest, rightSideView) {
  std::vector<int> nums1 = {1, 2, -1, 5, -1, -1, 3, -1, 4, -1, -1};
  TreeNode<int>* root1 = ToBinaryTree(nums1);
  std::vector<int> res1 = exec->rightSideView(root1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(3, res1.at(1));
  ASSERT_EQ(4, res1.at(2));
  FreeBinaryTree(root1);

  std::vector<int> nums2 = {1, -1, 3, -1, -1};
  TreeNode<int>* root2 = ToBinaryTree(nums2);
  std::vector<int> res2 = exec->rightSideView(root2);
  ASSERT_EQ(1, res2.at(0));
  ASSERT_EQ(3, res2.at(1));
  FreeBinaryTree(root2);

  std::vector<int> nums3 = {};
  TreeNode<int>* root3 = ToBinaryTree(nums3);
  std::vector<int> res3 = exec->rightSideView(root3);
  ASSERT_EQ(0, res3.size());
  FreeBinaryTree(root3);
}
}  // namespace tree
}  // namespace algo
