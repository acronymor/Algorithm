#include "array/lc_974_subarray_sums_divisible_by_k.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class SubarraysDivByKTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SubarraysDivByK(); }

  void TearDown() override { delete exec; }

 protected:
  SubarraysDivByK* exec{nullptr};
};

TEST_F(SubarraysDivByKTest, solve) {
  std::vector<int> nums1 = {4, 5, 0, -2, -3, 1};
  int k1 = 5;
  ASSERT_EQ(7, exec->solve(nums1, k1));

  std::vector<int> nums2 = {5};
  int k2 = 9;
  ASSERT_EQ(0, exec->solve(nums2, k2));
}
}  // namespace array
}  // namespace algo
