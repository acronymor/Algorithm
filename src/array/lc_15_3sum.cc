#include "array/lc_15_3sum.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class ThreeSumTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ThreeSum(); }

  void TearDown() override { delete exec; }

 protected:
  ThreeSum* exec{nullptr};
};

TEST_F(ThreeSumTest, threeSum1) {
  std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> res1 = exec->threeSum1(nums1);
  ASSERT_EQ(0, res1[0][0]);
  ASSERT_EQ(1, res1[0][2]);
  ASSERT_EQ(-1, res1[1][0]);
  ASSERT_EQ(2, res1[1][2]);

  std::vector<int> nums2 = {0, 1, 1};
  std::vector<std::vector<int>> res2 = exec->threeSum1(nums2);
  ASSERT_EQ(0, res2.size());

  std::vector<int> nums3 = {0, 0, 0};
  std::vector<std::vector<int>> res3 = exec->threeSum1(nums3);
  ASSERT_EQ(0, res3[0][0]);
  ASSERT_EQ(0, res3[0][1]);
  ASSERT_EQ(0, res3[0][2]);
}

TEST_F(ThreeSumTest, threeSum2) {
  std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> res1 = exec->threeSum2(nums1);
  ASSERT_EQ(-1, res1[0][0]);
  ASSERT_EQ(2, res1[0][2]);
  ASSERT_EQ(-1, res1[1][0]);
  ASSERT_EQ(1, res1[1][2]);

  std::vector<int> nums2 = {0, 1, 1};
  std::vector<std::vector<int>> res2 = exec->threeSum2(nums2);
  ASSERT_EQ(0, res2.size());

  std::vector<int> nums3 = {0, 0, 0};
  std::vector<std::vector<int>> res3 = exec->threeSum2(nums3);
  ASSERT_EQ(0, res3[0][0]);
  ASSERT_EQ(0, res3[0][1]);
  ASSERT_EQ(0, res3[0][2]);
}
}  // namespace array
}  // namespace algo
