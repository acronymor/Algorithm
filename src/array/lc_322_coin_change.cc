#include "array/lc_322_coin_change.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CoinChangeTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CoinChange(); }

  void TearDown() override { delete exec; }

 protected:
  CoinChange* exec{nullptr};
};

TEST_F(CoinChangeTest, solve1) {
  std::vector<int> nums1 = {1, 2, 5};
  ASSERT_EQ(3, exec->solve1(nums1, 11));

  std::vector<int> nums2 = {2};
  ASSERT_EQ(-1, exec->solve1(nums2, 3));

  std::vector<int> nums3 = {1};
  ASSERT_EQ(0, exec->solve1(nums3, 0));
};

TEST_F(CoinChangeTest, solve2) {
  std::vector<int> nums1 = {1, 2, 5};
  ASSERT_EQ(3, exec->solve2(nums1, 11));

  std::vector<int> nums2 = {2};
  ASSERT_EQ(-1, exec->solve2(nums2, 3));

  std::vector<int> nums3 = {1};
  ASSERT_EQ(0, exec->solve2(nums3, 0));
}
}  // namespace array
}  // namespace algo