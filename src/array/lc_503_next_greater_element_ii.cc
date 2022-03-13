#include "array/lc_503_next_greater_element_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class NextGreaterElementIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new NextGreaterElementII(); }

  void TearDown() override { delete exec; }

 protected:
  NextGreaterElementII* exec{nullptr};
};

TEST_F(NextGreaterElementIITest, maxArea) {
  std::vector<int> nums1 = {1, 2, 1};
  std::vector<int> res1 = exec->nextGreaterElements(nums1);
  ASSERT_EQ(2, res1[0]);
  ASSERT_EQ(-1, res1[1]);
  ASSERT_EQ(2, res1[2]);

  std::vector<int> nums2 = {1, 2, 3, 4, 3};
  std::vector<int> res2 = exec->nextGreaterElements(nums2);
  ASSERT_EQ(2, res2[0]);
  ASSERT_EQ(4, res2[2]);
  ASSERT_EQ(4, res2[4]);
}
}  // namespace array
}  // namespace algo
