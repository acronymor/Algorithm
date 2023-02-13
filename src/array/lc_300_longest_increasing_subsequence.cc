#include "array/lc_300_longest_increasing_subsequence.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class LengthOfLISTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LengthOfLIS(); }

  void TearDown() override { delete exec; }

 protected:
  LengthOfLIS* exec{nullptr};
};

TEST_F(LengthOfLISTest, solve) {
  std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
  ASSERT_EQ(4, exec->solve(nums1));

  std::vector<int> nums2 = {0, 1, 0, 3, 2, 3};
  ASSERT_EQ(4, exec->solve(nums2));

  std::vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
  ASSERT_EQ(1, exec->solve(nums3));
};
}  // namespace array
}  // namespace algo
