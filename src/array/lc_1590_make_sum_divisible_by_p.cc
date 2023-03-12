#include "array/lc_1590_make_sum_divisible_by_p.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MinSubarrayTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MinSubarray(); }

  void TearDown() override { delete exec; }

 protected:
  MinSubarray* exec{nullptr};
};

TEST_F(MinSubarrayTest, solve) {
  std::vector<int> nums1 = {3, 1, 4, 2};
  int k1 = 6;
  ASSERT_EQ(1, exec->solve(nums1, k1));

  std::vector<int> nums2 = {6, 3, 5, 2};
  int k2 = 9;
  ASSERT_EQ(2, exec->solve(nums2, k2));

  std::vector<int> nums3 = {1, 2, 3};
  int k3 = 3;
  ASSERT_EQ(0, exec->solve(nums3, k3));

  std::vector<int> nums4 = {1, 2, 3};
  int k4 = 7;
  ASSERT_EQ(-1, exec->solve(nums4, k4));

  std::vector<int> nums5 = {1000000000, 1000000000, 1000000000};
  int k5 = 3;
  ASSERT_EQ(0, exec->solve(nums5, k5));
}
}  // namespace array
}  // namespace algo
