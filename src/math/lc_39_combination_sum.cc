#include "math/lc_39_combination_sum.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class CombineSumTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CombineSum(); }

  void TearDown() override { delete exec; }

 protected:
  CombineSum* exec{nullptr};
};

TEST_F(CombineSumTest, combine) {
  std::vector<int> nums1 = {2, 3, 6, 7};
  std::vector<std::vector<int>> res1 = exec->combineSum(nums1, 7);
  ASSERT_EQ(2, res1[0][0]);
  ASSERT_EQ(2, res1[0][1]);
  ASSERT_EQ(3, res1[0][2]);
  ASSERT_EQ(7, res1[1][0]);

  std::vector<int> nums2 = {2};
  std::vector<std::vector<int>> res2 = exec->combineSum(nums2, 1);
  ASSERT_EQ(0, res2.size());
}

}  // namespace math
}  // namespace algo
