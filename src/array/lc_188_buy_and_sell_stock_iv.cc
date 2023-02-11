#include "array/lc_188_buy_and_sell_stock_iv.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxProfitIVTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxProfitIV(); }

  void TearDown() override { delete exec; }

 protected:
  MaxProfitIV* exec{nullptr};
};

TEST_F(MaxProfitIVTest, solve) {
  std::vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(7, exec->solve(nums1, 2));

  std::vector<int> nums2 = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, exec->solve(nums2, 2));

  std::vector<int> nums3 = {3, 3, 5, 0, 0, 3, 1, 4};
  ASSERT_EQ(6, exec->solve(nums3, 2));
};
};  // namespace array
}  // namespace algo
