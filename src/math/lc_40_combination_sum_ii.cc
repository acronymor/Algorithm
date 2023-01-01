#include "math/lc_40_combination_sum_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class CombineSumIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CombineSumII(); }

  void TearDown() override { delete exec; }

 protected:
  CombineSumII* exec{nullptr};
};

TEST_F(CombineSumIITest, combine) {
  std::vector<int> nums1 = {10, 1, 2, 7, 6, 1, 5};
  std::vector<std::vector<int>> res1 = exec->combineSum(nums1, 8);
  ASSERT_EQ(2, res1[0][0]);
  ASSERT_EQ(2, res1[0][1]);
  ASSERT_EQ(3, res1[0][2]);
  ASSERT_EQ(7, res1[1][0]);

  std::vector<int> nums2 = {2, 5, 2, 1, 2};
  std::vector<std::vector<int>> res2 = exec->combineSum(nums2, 5);
  ASSERT_EQ(0, res2.size());
}

}  // namespace math
}  // namespace algo
