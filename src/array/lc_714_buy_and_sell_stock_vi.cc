#include "array/lc_714_buy_and_sell_stock_vi.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxProfitVITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxProfitVI(); }

  void TearDown() override { delete exec; }

 protected:
  MaxProfitVI* exec{nullptr};
};

TEST_F(MaxProfitVITest, solve) {
  std::vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(3, exec->solve(nums1, 2));

  std::vector<int> nums2 = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, exec->solve(nums2, 1));

  std::vector<int> nums3 = {1, 3, 2, 8, 4, 9};
  ASSERT_EQ(8, exec->solve(nums3, 2));
};
};  // namespace array
}  // namespace algo
