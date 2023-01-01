#include "math/lc_377_combination_sum_iv.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class CombineSumIVTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CombineSumIV(); }

  void TearDown() override { delete exec; }

 protected:
  CombineSumIV* exec{nullptr};
};

TEST_F(CombineSumIVTest, combine1) {
  std::vector<int> nums1 = {1, 2, 3};
  ASSERT_EQ(7, exec->combineSum1(nums1, 4));

  std::vector<int> nums2 = {9};
  ASSERT_EQ(0, exec->combineSum1(nums2, 3));
}

TEST_F(CombineSumIVTest, combine2) {
  std::vector<int> nums1 = {1, 2, 3};
  ASSERT_EQ(7, exec->combineSum2(nums1, 4));

  std::vector<int> nums2 = {9};
  ASSERT_EQ(0, exec->combineSum2(nums2, 3));
}
}  // namespace math
}  // namespace algo
