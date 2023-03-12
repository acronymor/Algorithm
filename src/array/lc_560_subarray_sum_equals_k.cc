#include "array/lc_560_subarray_sum_equals_k.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class SubarraySumTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SubarraySum(); }

  void TearDown() override { delete exec; }

 protected:
  SubarraySum* exec{nullptr};
};

TEST_F(SubarraySumTest, solve) {
  std::vector<int> nums1 = {1, 1, 1};
  int k1 = 2;
  ASSERT_EQ(2, exec->solve(nums1, k1));

  std::vector<int> nums2 = {1, 2, 3};
  int k2 = 3;
  ASSERT_EQ(2, exec->solve(nums2, k2));
};
}  // namespace array
}  // namespace algo
