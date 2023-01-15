#include "array/lc_1049_last_stone_weight_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class LastStoneWeightIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LastStoneWeightII(); }

  void TearDown() override { delete exec; }

 protected:
  LastStoneWeightII* exec{nullptr};
};

TEST_F(LastStoneWeightIITest, solve1) {
  std::vector<int> nums1 = {2, 7, 4, 1, 8, 1};
  ASSERT_EQ(1, exec->solve1(nums1));

  std::vector<int> nums2 = {31, 26, 33, 21, 40};
  ASSERT_EQ(5, exec->solve1(nums2));
}

TEST_F(LastStoneWeightIITest, solve2) {
  std::vector<int> nums1 = {2, 7, 4, 1, 8, 1};
  ASSERT_EQ(1, exec->solve2(nums1));

  std::vector<int> nums2 = {31, 26, 33, 21, 40};
  ASSERT_EQ(5, exec->solve2(nums2));
}

}  // namespace array
}  // namespace algo