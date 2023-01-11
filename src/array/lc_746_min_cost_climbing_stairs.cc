#include "array/lc_746_min_cost_climbing_stairs.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MinCostClimbingStairsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MinCostClimbingStairs(); }

  void TearDown() override { delete exec; }

 protected:
  MinCostClimbingStairs* exec{nullptr};
};

TEST_F(MinCostClimbingStairsTest, climbStairs) {
  std::vector<int> nums1 = {10, 15, 20};
  ASSERT_EQ(15, exec->minCostClimbingStairs(nums1));

  std::vector<int> nums2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  ASSERT_EQ(6, exec->minCostClimbingStairs(nums2));
};
}  // namespace array
};  // namespace algo
