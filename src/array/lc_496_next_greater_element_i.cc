#include "array/lc_496_next_greater_element_i.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class NextGreaterElementITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new NextGreaterElementI(); }

  void TearDown() override { delete exec; }

 protected:
  NextGreaterElementI* exec{nullptr};
};

TEST_F(NextGreaterElementITest, maxArea) {
  std::vector<int> nums1 = {4, 1, 2};
  std::vector<int> nums2 = {1, 3, 4, 2};
  std::vector<int> res1 = exec->nextGreaterElement(nums1, nums2);
  ASSERT_EQ(-1, res1[0]);
  ASSERT_EQ(3, res1[1]);
  ASSERT_EQ(-1, res1[2]);

  std::vector<int> nums3 = {2, 4};
  std::vector<int> nums4 = {1, 2, 3, 4};
  std::vector<int> res2 = exec->nextGreaterElement(nums3, nums4);
  ASSERT_EQ(3, res2[0]);
  ASSERT_EQ(-1, res2[1]);

  std::vector<int> nums5 = {1, 3, 5, 2, 4};
  std::vector<int> nums6 = {5, 4, 3, 2, 1};
  std::vector<int> res3 = exec->nextGreaterElement(nums5, nums6);
  ASSERT_EQ(-1, res3[0]);
  ASSERT_EQ(-1, res3[2]);
  ASSERT_EQ(-1, res3[4]);
}
}  // namespace array
}  // namespace algo
