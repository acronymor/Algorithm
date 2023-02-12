#include "array/lc_309_buy_and_sell_stock_v.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxProfitVTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxProfitV(); }

  void TearDown() override { delete exec; }

 protected:
  MaxProfitV* exec{nullptr};
};

TEST_F(MaxProfitVTest, solve) {
  std::vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(5, exec->solve(nums1));

  std::vector<int> nums2 = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, exec->solve(nums2));

  std::vector<int> nums3 = {3, 3, 5, 0, 0, 3, 1, 4};
  ASSERT_EQ(6, exec->solve(nums3));
};
};  // namespace array
}  // namespace algo
