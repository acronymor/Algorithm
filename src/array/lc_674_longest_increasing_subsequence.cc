#include "array/lc_674_longest_increasing_subsequence.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class LengthOfLCISTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LengthOfLCIS(); }

  void TearDown() override { delete exec; }

 protected:
  LengthOfLCIS* exec{nullptr};
};

TEST_F(LengthOfLCISTest, solve1) {
  std::vector<int> nums1 = {1, 3, 5, 4, 7};
  ASSERT_EQ(3, exec->solve1(nums1));

  std::vector<int> nums2 = {7, 7, 7, 7, 7, 7, 7};
  ASSERT_EQ(1, exec->solve1(nums2));
};

TEST_F(LengthOfLCISTest, solve2) {
  std::vector<int> nums1 = {1, 3, 5, 4, 7};
  ASSERT_EQ(3, exec->solve2(nums1));

  std::vector<int> nums2 = {7, 7, 7, 7, 7, 7, 7};
  ASSERT_EQ(1, exec->solve2(nums2));
};
}  // namespace array
}  // namespace algo
