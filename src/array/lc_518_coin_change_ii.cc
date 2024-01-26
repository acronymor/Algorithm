#include "array/lc_518_coin_change_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CoinChangeIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CoinChangeII(); }

  void TearDown() override { delete exec; }

 protected:
  CoinChangeII* exec{nullptr};
};

TEST_F(CoinChangeIITest, change) {
  std::vector<int> nums1 = {1, 2, 5};
  int amount1 = 5;
  ASSERT_EQ(4, exec->change(amount1, nums1));

  std::vector<int> nums2 = {2};
  int amount2 = 3;
  ASSERT_EQ(0, exec->change(amount2, nums2));

  std::vector<int> nums3 = {10};
  int amount3 = 10;
  ASSERT_EQ(1, exec->change(amount3, nums3));
};
}  // namespace array
}  // namespace algo
