#include "array/lc_494_target_sum.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FindTargetSumWaysTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FindTargetSumWays(); }

  void TearDown() override { delete exec; }

 protected:
  FindTargetSumWays* exec{nullptr};
};

TEST_F(FindTargetSumWaysTest, solve2) {
  std::vector<int> nums1 = {1, 1, 1, 1, 1};
  ASSERT_EQ(5, exec->solve2(nums1, 3));

  std::vector<int> nums2 = {1};
  ASSERT_EQ(1, exec->solve2(nums2, 1));

  std::vector<int> nums3 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
  ASSERT_EQ(256, exec->solve2(nums3, 1));
}

TEST_F(FindTargetSumWaysTest, solve3) {
  std::vector<int> nums1 = {1, 1, 1, 1, 1};
  ASSERT_EQ(5, exec->solve3(nums1, 3));

  std::vector<int> nums2 = {1};
  ASSERT_EQ(1, exec->solve3(nums2, 1));

  std::vector<int> nums3 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
  ASSERT_EQ(256, exec->solve3(nums3, 1));
}
}  // namespace array
}  // namespace algo
