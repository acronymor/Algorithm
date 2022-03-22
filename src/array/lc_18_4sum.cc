#include "array/lc_18_4sum.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FourSumTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FourSum(); }

  void TearDown() override { delete exec; }

 protected:
  FourSum* exec{nullptr};
};

TEST_F(FourSumTest, fourSum) {
  std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
  std::vector<std::vector<int>> res1 = exec->fourSum(nums1, 0);
  ASSERT_EQ(-2, res1[0][0]);
  ASSERT_EQ(2, res1[0][3]);
  ASSERT_EQ(-2, res1[1][0]);
  ASSERT_EQ(2, res1[1][3]);
  ASSERT_EQ(-1, res1[2][0]);
  ASSERT_EQ(1, res1[2][3]);

  std::vector<int> nums2 = {2, 2, 2, 2, 2};
  std::vector<std::vector<int>> res2 = exec->fourSum(nums2, 8);
  ASSERT_EQ(2, res2[0][0]);
}
}  // namespace array
}  // namespace algo
