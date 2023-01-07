#include "array/lc_376_wiggle_subsequence.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class WiggleMaxLengthTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new WiggleMaxLength(); }

  void TearDown() override { delete exec; }

 protected:
  WiggleMaxLength* exec{nullptr};
};

TEST_F(WiggleMaxLengthTest, solve1) {
  std::vector<int> nums1 = {1, 7, 4, 9, 2, 5};
  ASSERT_EQ(6, exec->solve1(nums1));

  std::vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  ASSERT_EQ(7, exec->solve1(nums2));
};

TEST_F(WiggleMaxLengthTest, solve2) {
  std::vector<int> nums1 = {1, 7, 4, 9, 2, 5};
  ASSERT_EQ(6, exec->solve2(nums1));

  std::vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  ASSERT_EQ(7, exec->solve2(nums2));
};
}  // namespace array
}  // namespace algo
