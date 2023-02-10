#include "array/lc_122_buy_and_sell_stock_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxProfitIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxProfitII(); }

  void TearDown() override { delete exec; }

 protected:
  MaxProfitII* exec{nullptr};
};

TEST_F(MaxProfitIITest, solve) {
  std::vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(7, exec->solve(nums1));

  std::vector<int> nums2 = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, exec->solve(nums2));
};
}  // namespace array
};  // namespace algo
