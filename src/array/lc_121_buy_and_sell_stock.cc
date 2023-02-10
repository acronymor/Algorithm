#include "array/lc_121_buy_and_sell_stock.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxProfitTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxProfit(); }

  void TearDown() override { delete exec; }

 protected:
  MaxProfit* exec{nullptr};
};

TEST_F(MaxProfitTest, solve1) {
  std::vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(5, exec->solve1(nums1));

  std::vector<int> nums2 = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, exec->solve1(nums2));
};

TEST_F(MaxProfitTest, solve2) {
  std::vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(5, exec->solve2(nums1));

  std::vector<int> nums2 = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, exec->solve2(nums2));
};
}  // namespace array
};  // namespace algo
