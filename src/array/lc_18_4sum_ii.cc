#include "array/lc_18_4sum_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FourSumIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FourSumII(); }

  void TearDown() override { delete exec; }

 protected:
  FourSumII* exec{nullptr};
};

TEST_F(FourSumIITest, fourSum) {
  std::vector<int> nums1 = {1, 2};
  std::vector<int> nums2 = {-2, -1};
  std::vector<int> nums3 = {-1, 2};
  std::vector<int> nums4 = {0, 2};
  int res = exec->fourSum(nums1, nums2, nums3, nums4);
  ASSERT_EQ(2, res);
}
}  // namespace array
}  // namespace algo
