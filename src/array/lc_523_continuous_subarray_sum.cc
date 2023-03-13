#include "array/lc_523_continuous_subarray_sum.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CheckSubarraySumTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CheckSubarraySum(); }

  void TearDown() override { delete exec; }

 protected:
  CheckSubarraySum* exec{nullptr};
};

TEST_F(CheckSubarraySumTest, solve) {
  std::vector<int> nums1 = {23, 2, 4, 6, 7};
  int k1 = 6;
  ASSERT_TRUE(exec->solve(nums1, k1));

  std::vector<int> nums2 = {23, 2, 6, 4, 7};
  int k2 = 13;
  ASSERT_FALSE(exec->solve(nums2, k2));

  std::vector<int> nums3 = {5, 0, 0, 0};
  int k3 = 3;
  ASSERT_TRUE(exec->solve(nums3, k3));
};
}  // namespace array
}  // namespace algo
